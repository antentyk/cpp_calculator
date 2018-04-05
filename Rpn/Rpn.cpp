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
        }
    }

    if(s.size() != 1)
        throw InvalidOperand();
    
    Token result = s.top();
    if(!result.isNumber())
        throw InvalidOperand();
    
    return result.getValue();
}