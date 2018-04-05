#include "TokensParser.h"

using namespace Calculator;
using std::vector;
using std::string;

TokensParser::TokensParser(string line):
    line(line)
{}

vector<Token> TokensParser::parse(){
    TokensStream strm(line);

    vector<Token> result;

    try{
        while(true){
            Token current = strm.get();

            // transforming binary +- operators
            // to unary +- operators
            // where it is necessary
            if
            (
                current.getType() == TokenType::BinaryPlus ||
                current.getType() == TokenType::BinaryMinus
            )
            {
                if(result.size() == 0){
                    result.push_back(
                        current.getType() == TokenType::BinaryPlus?
                            Token(TokenType::UnaryPlus):
                            Token(TokenType::UnaryMinus)
                    );
                    continue;
                }

                Token previous = result.back();
                if
                (
                    previous.isOperator() ||
                    previous.getType() == TokenType::LeftBracket
                )
                {
                    result.push_back(
                        current.getType() == TokenType::BinaryPlus?
                            Token(TokenType::UnaryPlus):
                            Token(TokenType::UnaryMinus)
                    );
                    continue;
                }
            }

            result.push_back(current);
        }
    }
    catch(const NoTokensLeft& e){
        return result;
    }
}