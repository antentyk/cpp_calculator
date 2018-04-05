#include "Tokens.h"

using namespace Calculator;

Token::Token(TokenType type):
    type(type),
    value(0)
{
    if(isNumber())
        throw NumberTokenInitialization();
}

Token::Token(TokenType type, double value):
    type(type),
    value(value)
{
    if(!isNumber())
        throw NonNumberTokenInitialization();
}

Token::operator double() const{
    if(!isNumber())
        throw TokenConvertion();
    
    return value;
}

TokenType Token::getType() const{
    return type;
}

double Token::getValue() const{
    if(!isNumber())
        throw TokenConvertion();
    
    return value;
}

bool Token::isOperator() const{
    return kOperators.find(type) != kOperators.end();
}

bool Token::isNumber() const{
    return type == TokenType::Number;
}

bool Token::isLeftAsociative() const{
    return kLeftAscoiative.find(type) != kLeftAscoiative.end();
}

bool Token::isRightAsociative() const{
    return kRightAsociative.find(type) != kRightAsociative.end();
}

bool Token::isBinary() const{
    return kBinary.find(type) != kBinary.end();
}

int Token::getPrecedence() const{
    auto itr = kPrecedence.find(type);
    if(itr == kPrecedence.end())
        throw PrecedenceError();
    
    return itr->second;
}