#ifndef TOKEN_H_
#define TOKEN_H_

#include "TokenType.h"
#include "../Exceptions/Exceptions.h"

namespace Calculator{
    class Token{
    public:
        explicit Token(TokenType type);
        Token(TokenType type, double value);

        operator double() const;

        TokenType getType() const;
        double getValue() const;

        bool isOperator() const;
        bool isNumber() const;
        bool isLeftAsociative() const;
        bool isRightAsociative() const;
        bool isBinary() const;

        int getPrecedence() const;
    private:
        TokenType type;
        double value;
    };
}

#endif