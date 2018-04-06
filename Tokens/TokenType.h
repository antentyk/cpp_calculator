#ifndef TOKEN_TYPE_H_
#define TOKEN_TYPE_H_

#include <set>
#include <map>
#include <cmath>
#include <algorithm>

namespace Calculator{
    enum class TokenType{
        Number,
        BinaryPlus,
        BinaryMinus,
        Multiplication,
        Division,
        Power,
        LeftBracket,
        RightBracket,

        UnaryPlus,
        UnaryMinus,

        Sine,
        Cosine,

        Delimiter,

        Min,
        Max
    };

    extern const std::set<TokenType>
        kOperators,
        kFunctions;
    extern const std::set<TokenType>
        kLeftAscoiative,
        kRightAsociative;
    extern const std::set<TokenType>
        kBinary,
        kUnary;
    extern const std::map<TokenType, int>
        kPrecedence;
    extern const std::map<TokenType, double(*)(double, double)>
        kBinaryFunctionMap;
    extern const std::map<TokenType, double(*)(double)>
        kUnaryFunctionMap;
    extern const std::map<char, TokenType>
        kCharRepresentation;
    extern const std::map<TokenType, char>
        kReversedCharRepresentation;

}

#endif