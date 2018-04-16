#include <sstream>
#include <boost/algorithm/string.hpp>

#include "Parser.h"

using namespace Calculator;
using std::string;
using std::vector;
using std::stringstream;
using boost::algorithm::replace_all;

Parser::Parser(string raw_line)
{
    tokens.clear();

    stringstream strm(prepare(raw_line));

    while(true){
        char current;

        strm >> current;
        if(strm.fail())return;

        auto itr = kReversedInternalRepresentation.find(current);
        if(itr != kReversedInternalRepresentation.end()){
            tokens.push_back(Token(itr->second));
            continue;
        }
        strm.putback(current);

        double value;
        strm >> value;
        if(strm.fail())
            throw InvalidToken();
        
        tokens.push_back(Token(TokenType::Number, value));
    }
}

std::string Parser::prepare(string raw_line){
    string result = raw_line;

    for(auto itr: kHumanRepresentation){
        TokenType token = itr.first;

        string humanRepresentation = itr.second;
        char internalRepresentation = kInternalRepresentation.at(token);

        if
        (
            humanRepresentation.size() != 1 ||
            humanRepresentation.at(0) != internalRepresentation
        )
            replace_all(
                result,
                humanRepresentation,
                string(1, internalRepresentation)
            );
    }

    return result;
}

void Parser::revert(){
    if(index == 0)
        throw NoRevertTokens();
    
    --index;
}

Token Parser::get(){
    if(empty())
        throw NoTokensLeft();
    
    return tokens[index++];
}

bool Parser::empty() const{
    return index == tokens.size();
}