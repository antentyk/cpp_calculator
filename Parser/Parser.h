#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>
#include <sstream>

#include <boost/algorithm/string.hpp>
#include "../Exceptions/Exceptions.h"
#include "../Tokens/Tokens.h"

namespace Calculator{
    class Parser{
    public:
        Parser(std::string raw_line);

        // restores the last token that was taken
        void revert(); // throws NoRevertTokens()
        // returns current token
        Token get(); // throws NoTokensLeft()
        // returns true if there are no tokens to be read
        bool empty() const;
    private:
        // converts raw_line to internal representation
        std::string prepare(std::string raw_line);

        std::vector<Token> tokens;
        size_t index{0};
    };
}

#endif