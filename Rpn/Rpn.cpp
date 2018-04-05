#include "Rpn.h"

using namespace Calculator;
using std::stack;
using std::vector;

double Rpn::evaluate(vector<Token> rpnRepresentation)
{
    stack<Token> s;

    for(auto it: rpnRepresentation){
        if(it.isNumber()){
            s.push(it);
            continue;
        }

        if(it.isBinary()){
            if(s.size() < 2)
                throw InvalidOperand();
            
            Token second = s.top();
            s.pop();
            Token first = s.top();
            s.pop();

            if(!first.isNumber() || !second.isNumber())
                throw InvalidOperand();
            
            double result = kBinaryFunctionMap.at(it.getType())(
                first.getValue(),
                second.getValue()
            );

            s.push(Token(TokenType::Number, result));
            
            continue;
        }

        if(it.isUnary()){
            if(s.size() < 1)
                throw InvalidOperand();
            
            Token first = s.top();
            s.pop();
            if(!first.isNumber())
                throw InvalidOperand();
            
            double result = kUnaryFunctionMap.at(it.getType())(
                first.getValue()
            );

            s.push(Token(TokenType::Number, result));
            continue;
        }

        throw InvalidToken();
    }

    if(s.size() != 1)
        throw InvalidOperand();
    
    Token result = s.top();
    if(!result.isNumber())
        throw InvalidOperand();
    
    return result.getValue();
}