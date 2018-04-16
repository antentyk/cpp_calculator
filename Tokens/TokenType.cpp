#include <cmath>
#include <algorithm>

#include "TokenType.h"

using namespace Calculator;
using std::map;
using std::set;

// defining functions that operators and functions
// should do on particular double values
namespace
{
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

    double MinFunc(double a, double b){
        return std::min(a, b);
    }
    double MaxFunc(double a, double b){
        return std::max(a, b);
    }
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
}

const set<TokenType>
    Calculator::kFactorUnaryOperators{
        TokenType::Plus,
        TokenType::Minus
    },
    Calculator::kFactorUnaryFunctions{
        TokenType::Sine,
        TokenType::Cosine
    },
    Calculator::kFactorBinaryFunctions{
        TokenType::Min,
        TokenType::Max,
        TokenType::Power
    };

const set<TokenType>
    Calculator::kTermBinaryOperators{
        TokenType::Division,
        TokenType::Multiplication
    };

const set<TokenType>
    Calculator::kExpressionBinaryOperators{
        TokenType::Plus,
        TokenType::Minus
    };

const map<TokenType, double(*)(double, double)>
    Calculator::kBinaryFunctionMap{
        {TokenType::Min, &MinFunc},
        {TokenType::Max, &MaxFunc},
        {TokenType::Plus, &BinaryPlusFunc},
        {TokenType::Minus, &BinaryMinusFunc},
        {TokenType::Multiplication, &MultiplicationFunc},
        {TokenType::Division, &DivisionFunc},
        {TokenType::Power, &PowerFunc}
    };

const map<TokenType, double(*)(double)>
    Calculator::kUnaryFunctionMap{
        {TokenType::Cosine, &CosineFunc},
        {TokenType::Sine, &SineFunc},
        {TokenType::Plus, &UnaryPlusFunc},
        {TokenType::Minus, &UnaryMinusFunc}
    };

const map<TokenType, std::string>
    Calculator::kHumanRepresentation{
        {TokenType::Plus, "+"},
        {TokenType::Minus, "-"},
        {TokenType::Multiplication, "*"},
        {TokenType::Division, "/"},
        {TokenType::Power, "pow"},
        {TokenType::LeftBracket, "("},
        {TokenType::RightBracket, ")"},
        {TokenType::Delimiter, ","},
        {TokenType::Sine, "sin"},
        {TokenType::Cosine, "cos"},
        {TokenType::Min, "min"},
        {TokenType::Max, "max"}
    };

const map<TokenType, char>
    Calculator::kInternalRepresentation{
        {TokenType::Plus, '+'},
        {TokenType::Minus, '-'},
        {TokenType::Multiplication, '*'},
        {TokenType::Division, '/'},
        {TokenType::Power, 'p'},
        {TokenType::LeftBracket, '('},
        {TokenType::RightBracket, ')'},
        {TokenType::Delimiter, ','},
        {TokenType::Sine, 's'},
        {TokenType::Cosine, 'c'},
        {TokenType::Min, 'i'},
        {TokenType::Max, 'a'}
    };

namespace{
    map<char, TokenType> initkReversedInternalRepresentation(){
        map<char, TokenType> result;
        for(auto it: kInternalRepresentation)
            result.insert({it.second, it.first});
        
        return result;
    }
}

const map<char, TokenType>
    Calculator::kReversedInternalRepresentation =
        initkReversedInternalRepresentation();