#include "GrammarParser.h"

using namespace Calculator;

GrammarParser::GrammarParser(Parser parser):
    parser(parser)
{}

double GrammarParser::Factor(){
    if(parser.empty())
        throw FactorFailure();

    Token current = parser.get();

    if(current.getType() == TokenType::Number) // rule no. 1
        return current.getValue();
    
    if(current.getType() == TokenType::LeftBracket){ // rule no. 2
        double expression = Expression();
        Token last = parser.get();
        if(last.getType() != TokenType::RightBracket)
            throw FactorFailure();
        return expression;
    }

    throw FactorFailure();
}

double GrammarParser::Term(){
    if(parser.empty())
        throw TermFailure();

    Token current = parser.get();

    // rule no. 4, 5
    if
    (
        kTermUnaryOperators.find(current.getType()) !=
        kTermUnaryOperators.end()
    )
        return kUnaryFunctionMap.at(current.getType())(Term());

    parser.revert();
    
    double factor = Factor();

    // rule no. 3
    if(parser.empty())
        return factor;
    
    // rule no. 6, 7, 8
    Token binary_operator = parser.get();
    
    if
    (
        kTermBinaryOperators.find(binary_operator.getType()) ==
        kTermBinaryOperators.end()
    )
    {
        parser.revert();
        return factor;
    }
    
    return kBinaryFunctionMap.at(binary_operator.getType())(factor, Term());
}

double GrammarParser::Expression(){
    if(parser.empty())
        throw ExpressionFailure();

    double result;

    Token current = parser.get();

    if
    (
        kExpressionUnaryFunctions.find(current.getType()) !=
        kExpressionUnaryFunctions.end()
    )
    {
        Token unary_function = current;

        if(parser.get().getType() != TokenType::LeftBracket)
            throw ExpressionFailure();
        
        double expression = Expression();

        if(parser.get().getType() != TokenType::RightBracket)
            throw ExpressionFailure();
        
        result = kUnaryFunctionMap.at(unary_function.getType())(expression);
    }
    else if
    (
        kExpressionBinaryFunctions.find(current.getType()) !=
        kExpressionBinaryFunctions.end()
    )
    {
        Token binary_function = current;

        if(parser.get().getType() != TokenType::LeftBracket)
            throw ExpressionFailure();
        
        double first_operand = Expression();

        if(parser.get().getType() != TokenType::Delimiter)
            throw ExpressionFailure();
        
        double second_operand = Expression();

        if(parser.get().getType() != TokenType::RightBracket)
            throw ExpressionFailure();
        
        result = kBinaryFunctionMap.at(binary_function.getType())(
            first_operand,
            second_operand
        );
    }
    else
    {
        parser.revert();
        result = Term();
    }

    // rule no. 9, 12, 15
    if(parser.empty())
        return result;

    // rule no 10, 11, 13, 14, 16, 17
    Token binary_operator = parser.get();
    if
    (
        kExpressionBinaryOperators.find(binary_operator.getType()) ==
        kExpressionBinaryOperators.end()
    )
    {
        parser.revert();
        return result;
    }
    return kBinaryFunctionMap.at(binary_operator.getType())(result, Expression());
}

double GrammarParser::evaluate(){
    double result = Expression();

    if(!parser.empty())
        throw OddTokensLeft();
    
    return result;
}