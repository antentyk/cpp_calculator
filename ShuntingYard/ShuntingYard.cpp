#include "ShuntingYard.h"

using namespace Calculator;
using std::vector;
using std::stack;
using std::queue;

vector<Token> ShuntingYard::transformToRpn(
    const vector<Token> &expression
)
{
    queue<Token> output_queue;
    stack<Token> operator_stack;

    for(auto token: expression){
        if(token.isFunction()){
            operator_stack.push(token);
            continue;
        }

        if(token.isNumber()){
            output_queue.push(token);
            continue;
        }

        if(token.isOperator()){
            while
            (
                !operator_stack.empty() &&
                operator_stack.top().getType() != TokenType::LeftBracket &&
                (
                    operator_stack.top().isFunction() ||
                    operator_stack.top().getPrecedence() > token.getPrecedence() ||
                    (
                        operator_stack.top().getPrecedence() == 
                            token.getPrecedence() && 
                        operator_stack.top().isLeftAsociative()
                    )
                )
            )
            {
                Token current = operator_stack.top();
                operator_stack.pop();
                output_queue.push(current);
            }
            operator_stack.push(token);
            continue;
        }

        if(token.getType() == TokenType::LeftBracket){
            operator_stack.push(token);
            continue;
        }

        if
        (
            token.getType() == TokenType::RightBracket ||
            token.getType() == TokenType::Delimiter
        )
        {
            while
            (
                !operator_stack.empty() &&
                operator_stack.top().getType() != TokenType::LeftBracket
            )
            {
                Token current = operator_stack.top();
                operator_stack.pop();
                output_queue.push(current);
            }

            if(operator_stack.empty())
                throw MismatchedBrackets();
            
            operator_stack.pop();

            if(token.getType() == TokenType::Delimiter)
                operator_stack.push(Token(TokenType::LeftBracket));

            continue;
        }
    }

    while(!operator_stack.empty()){
        Token current = operator_stack.top();
        operator_stack.pop();
        if
        (
            current.getType() == TokenType::LeftBracket ||
            current.getType() == TokenType::RightBracket
        )
            throw MismatchedBrackets();
        
        output_queue.push(current);
    }

    vector<Token> result;
    while(!output_queue.empty()){
        Token current = output_queue.front();
        result.push_back(current);
        output_queue.pop();
    }

    return result;
}