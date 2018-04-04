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
}

const set<TokenType>
    Calculator::kOperators{
        TokenType::BinaryPlus,
        TokenType::BinaryMinus,
        TokenType::Multiplication,
        TokenType::Division,
        TokenType::Power
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

const map<TokenType, int>
    Calculator::kPrecedence{
        {TokenType::BinaryPlus, 2},
        {TokenType::BinaryPlus, 2},
        {TokenType::Division, 3},
        {TokenType::Multiplication, 3},
        {TokenType::Power, 4}
    };

const map<TokenType, double(*)(double, double)>
    Calculator::kBinaryFunctionMap{
        {TokenType::BinaryPlus, &BinaryPlusFunc},
        {TokenType::BinaryMinus, &BinaryMinusFunc},
        {TokenType::Multiplication, &MultiplicationFunc},
        {TokenType::Division, &DivisionFunc},
        {TokenType::Power, &PowerFunc}
    };

const map<char, TokenType>
    Calculator::kCharRepresentation{
        {'+', TokenType::BinaryPlus},
        {'-', TokenType::BinaryMinus},
        {'*', TokenType::Multiplication},
        {'/', TokenType::Division},
        {'^', TokenType::Power},
        {'(', TokenType::LeftBracket},
        {')', TokenType::RightBracket}
    };
