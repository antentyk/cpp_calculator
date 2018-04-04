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
    private:
        TokenType type;
        double value;
    };
}

#endif