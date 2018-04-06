#include "Tokens.h"

using namespace Calculator;

Token::Token(TokenType type):
    type(type)
{
    if(type == TokenType::Number)
        throw TokenInitialization();
}

Token::Token(TokenType type, double value):
    type(type),
    value(value)
{
    if(type != TokenType::Number)
        throw TokenInitialization();
}

TokenType Token::getType() const{
    return type;
}

double Token::getValue() const{
    if(type != TokenType::Number)
        throw NoValue();
    
    return value;
}