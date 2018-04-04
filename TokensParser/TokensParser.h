#ifndef TOKENS_PARSER_H_
#define TOKENS_PARSER_H_

#include <vector>
#include <string>

#include "../Tokens/Tokens.h"
#include "../TokensStream/TokensStream.h"
#include "../Exceptions/Exceptions.h"

namespace Calculator{
    class TokensParser{
    public:
        TokensParser(std::string line);
        std::vector<Token> parse();
    private:
        std::string line;
    };
}

#endif