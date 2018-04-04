#include "Tokens.h"

using namespace Calculator;

Token::Token(TokenType type):
    type(type),
    value(0)
{
    if(type == TokenType::Number)
        throw NumberTokenInitialization();
}

Token::Token(TokenType type, double value):
    type(type),
    value(value)
{
    if(type != TokenType::Number)
        throw NonNumberTokenInitialization();
}

Token::operator double() const{
    if(type != TokenType::Number)
        throw TokenConvertion();
    
    return value;
}