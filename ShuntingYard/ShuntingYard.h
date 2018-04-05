#ifndef SHUNTING_YARD_H_
#define SHUNTING_YARD_H_

#include <stack>
#include <queue>
#include <vector>

#include "../Tokens/Tokens.h"

namespace Calculator{
    class ShuntingYard{
    public:
        static std::vector<Token> transformToRpn(
            const std::vector<Token> &expression
        );
    };
}

#endif