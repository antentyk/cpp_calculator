#include "TokenType.h"

using namespace Calculator;
using std::map;
using std::set;

namespace
{
    double BinaryPlusFunc(double a, double b){
        return a + b;
    }
    double BinaryMinusFunc(double a, double b){
        return a - b;
    }
    double MultiplicationFunc(double a, double b){
        return a * b;
    }
    double DivisionFunc(double a, double b){
        return a / b;
    }
    double PowerFunc(double a, double b){
        return pow(a, b);
    }
    
    double UnaryPlusFunc(double a){
        return a;
    }
    double UnaryMinusFunc(double a){
        return -a;
    }

    double SineFunc(double a){
        return sin(a);
    }
    double CosineFunc(double a){
        return cos(a);
    }
}

const set<TokenType>
    Calculator::kOperators{
        TokenType::BinaryPlus,
        TokenType::BinaryMinus,
        TokenType::Multiplication,
        TokenType::Division,
        TokenType::Power,

        TokenType::UnaryPlus,
        TokenType::UnaryMinus
    },
    Calculator::kFunctions{
        TokenType::Sine,
        TokenType::Cosine
    };

const set<TokenType>
    Calculator::kLeftAscoiative{
        TokenType::Multiplication,
        TokenType::Division,
        TokenType::BinaryPlus,
        TokenType::BinaryMinus
    };

const set<TokenType>
    Calculator::kRightAsociative{
        TokenType::Power
    };

const set<TokenType>
    Calculator::kBinary{
        TokenType::BinaryPlus,
        TokenType::BinaryMinus,
        TokenType::Multiplication,
        TokenType::Division,
        TokenType::Power,
    },
    Calculator::kUnary{
        TokenType::UnaryPlus,
        TokenType::UnaryMinus,

        TokenType::Sine,
        TokenType::Cosine
    };

const map<TokenType, int>
    Calculator::kPrecedence{
        {TokenType::BinaryPlus, 2},
        {TokenType::BinaryMinus, 2},
        {TokenType::Division, 3},
        {TokenType::Multiplication, 3},
        {TokenType::UnaryPlus, 4},
        {TokenType::UnaryMinus, 4},
        {TokenType::Power, 5}
    };

const map<TokenType, double(*)(double, double)>
    Calculator::kBinaryFunctionMap{
        {TokenType::BinaryPlus, &BinaryPlusFunc},
        {TokenType::BinaryMinus, &BinaryMinusFunc},
        {TokenType::Multiplication, &MultiplicationFunc},
        {TokenType::Division, &DivisionFunc},
        {TokenType::Power, &PowerFunc}
    };

const map<TokenType, double(*)(double)>
    Calculator::kUnaryFunctionMap{
        {TokenType::UnaryPlus, &UnaryPlusFunc},
        {TokenType::UnaryMinus, &UnaryMinusFunc},
        {TokenType::Cosine, &CosineFunc},
        {TokenType::Sine, &SineFunc}
    };

const map<char, TokenType>
    Calculator::kCharRepresentation{
        {'+', TokenType::BinaryPlus},
        {'-', TokenType::BinaryMinus},
        {'*', TokenType::Multiplication},
        {'/', TokenType::Division},
        {'^', TokenType::Power},
        {'(', TokenType::LeftBracket},
        {')', TokenType::RightBracket},
        {'s', TokenType::Sine},
        {'c', TokenType::Cosine}
    };

const map<TokenType, char>
    Calculator::kReversedCharRepresentation{
        {TokenType::Sine, 's'},
        {TokenType::Cosine, 'c'}
    };