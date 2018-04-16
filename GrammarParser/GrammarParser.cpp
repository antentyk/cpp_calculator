#include "GrammarParser.h"

#include "../Tokens/Tokens.h"
#include "../Exceptions/Exceptions.h"

using namespace Calculator;

GrammarParser::GrammarParser(Parser parser):
    parser(parser)
{}

double GrammarParser::Factor(){
    if(parser.empty())
        throw FactorFailure();
    
    Token current = parser.get();

    // rule no. 1 and 2
    if(kFactorUnaryOperators.find(current.getType()) != kFactorUnaryOperators.end())
        return kUnaryFunctionMap.at(current.getType())(Factor());
    
    // rule no 3
    if(kFactorBinaryFunctions.find(current.getType()) != kFactorBinaryFunctions.end())
    {
        if(parser.get().getType() != TokenType::LeftBracket)
            throw FactorFailure();
        
        double lhs = Expression();

        if(parser.get().getType() != TokenType::Delimiter)
            throw FactorFailure();
        
        double rhs = Expression();

        if(parser.get().getType() != TokenType::RightBracket)
            throw FactorFailure();

        return kBinaryFunctionMap.at(current.getType())(lhs, rhs);
    }

    // rule no. 4
    if(kFactorUnaryFunctions.find(current.getType()) != kFactorUnaryFunctions.end())
    {
        if(parser.get().getType() != TokenType::LeftBracket)
            throw FactorFailure();
        
        double lhs = Expression();

        if(parser.get().getType() != TokenType::RightBracket)
            throw FactorFailure();
        
        return kUnaryFunctionMap.at(current.getType())(lhs);
    }

    // rule no. 5
    if(current.getType() == TokenType::LeftBracket){
        double expression = Expression();

        if(parser.get().getType() != TokenType::RightBracket)
            throw FactorFailure();
        
        return expression;
    }

    // rule no. 6
    if(current.getType() == TokenType::Number)
        return current.getValue();
    
    throw FactorFailure();
}

double GrammarParser::Term(){
    if(parser.empty())
        throw TermFailure();

    // rule no. 9
    double result = Factor();

    while(!parser.empty())
    {
        Token current = parser.get();

        // rule no. 7 8
        if(kTermBinaryOperators.find(current.getType()) != kTermBinaryOperators.end())
        {
            result = kBinaryFunctionMap.at(current.getType())(result, Factor());
            continue;
        }

        parser.revert();
        break;
    }

    return result;
}

double GrammarParser::Expression(){
    if(parser.empty())
        throw ExpressionFailure();
    
    // rule no. 12
    double result = Term();

    while(!parser.empty())
    {
        Token current = parser.get();

        // rule no. 10 11
        if(kExpressionBinaryOperators.find(current.getType()) != kExpressionBinaryOperators.end())
        {
            result = kBinaryFunctionMap.at(current.getType())(result, Term());
            continue;
        }

        parser.revert();
        break;
    }

    return result;
}

double GrammarParser::evaluate(){
    double result = Expression();

    if(!parser.empty())
        throw OddTokensLeft();
    
    return result;
}