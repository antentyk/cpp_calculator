#ifndef TOKENS_H_
#define TOKENS_H_

#include "TokenType.h"
#include "../Exceptions/Exceptions.h"

namespace Calculator{
    class Token{
    // representation of the Token
    // that has type and value(only for Number)
    public:
        // if constructor is inappropriate
        // throws TokenInitialization()
        Token(TokenType type, double value); // for Number only
        explicit Token(TokenType type); // for all the rest types
    
        TokenType getType() const;
        // for Number only
        double getValue() const; // throws NoValue()
    private:
        TokenType type;
        double value{0};
    };
}

#endif