#include "TokensStream.h"

using namespace Calculator;

TokensStream::TokensStream(std::string line):
    strm(std::stringstream(line))
{}

Token TokensStream::get(){
    char current;

    strm >> current;
    if(strm.fail())
        throw NoTokensLeft();
    
    auto itr = kCharRepresentation.find(current);
    if(itr != kCharRepresentation.end())
        return Token(itr->second);
    
    strm.putback(current);

    double value;
    strm >> value;

    if(strm.fail())
        throw InvalidToken();
    
    return Token(TokenType::Number, value);
}