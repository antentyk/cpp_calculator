#ifndef TOKEN_TYPE_H_
#define TOKEN_TYPE_H_

#include <set>
#include <map>
#include <string>

namespace Calculator{
    // list of all tokens in the grammar
    enum class TokenType{
        Number,

        Plus,
        Minus,

        Multiplication,
        Division,
        Power,

        LeftBracket,
        RightBracket,
        Delimiter,

        Sine,
        Cosine,

        Min,
        Max
    };

    // defining operators and functions for each part of the grammar
    // for Factor
    extern const std::set<TokenType>
        kFactorUnaryOperators,
        kFactorUnaryFunctions,
        kFactorBinaryFunctions;

    // Term
    extern const std::set<TokenType>
        kTermBinaryOperators;
    
    // and Expression
    extern const std::set<TokenType>
        kExpressionBinaryOperators;

    // mapping operators and functions to actual functions that they should do
    // for binary
    extern const std::map<TokenType, double(*)(double, double)>
        kBinaryFunctionMap;
    // and unary
    extern const std::map<TokenType, double(*)(double)>
        kUnaryFunctionMap;
    
    // defining human representation of operators
    // and functions
    extern const std::map<TokenType, std::string>
        kHumanRepresentation;
    // defining internal representation of operators
    // and functions (made it char for easier parsing)
    extern const std::map<TokenType, char>
        kInternalRepresentation;
    // reversed internal representation is needed for parser
    // to detect a token
    extern const std::map<char, TokenType>
        kReversedInternalRepresentation;
}

#endif