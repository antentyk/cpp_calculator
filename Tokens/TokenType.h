#ifndef TOKEN_TYPE_H_
#define TOKEN_TYPE_H_

#include <set>
#include <map>
#include <cmath>

namespace Calculator{
    enum class TokenType{
        Number,
        BinaryPlus,
        BinaryMinus,
        Multiplication,
        Division,
        Power,
        LeftBracket,
        RightBracket
    };

    extern const std::set<TokenType>
        kOperators;
    extern const std::set<TokenType>
        kLeftAscoiative,
        kRightAsociative;
    extern const std::map<TokenType, int>
        kPrecedence;
    extern const std::map<TokenType, double(*)(double, double)>
        kBinaryFunctionMap;
    extern const std::map<char, TokenType>
        kCharRepresentation;
}

#endif