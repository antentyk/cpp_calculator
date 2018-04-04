#include "TokensParser.h"

using namespace Calculator;
using std::vector;
using std::string;

TokensParser::TokensParser(string line):
    line(line)
{}

vector<Token> TokensParser::parse(){
    TokensStream strm(line);

    vector<Token> result;

    try{
        while(true)
            result.push_back(strm.get());
    }
    catch(const NoTokensLeft& e){
        return result;
    }
}