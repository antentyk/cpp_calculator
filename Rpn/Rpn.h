#ifndef RPM_H_
#define RPN_H_

#include <stack>
#include <vector>

#include "../Tokens/Tokens.h"
#include "../Exceptions/Exceptions.h"

namespace Calculator{
    class Rpn{
    public:
        static double evaluate(std::vector<Token> rpnRepresentation);
    };
}

#endif