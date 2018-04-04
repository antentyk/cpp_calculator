#ifndef TOKENS_STREAM_H_
#define TOKENS_STREAM_H_

#include <string>
#include <sstream>

#include "../Tokens/Tokens.h"
#include "../Exceptions/Exceptions.h"

namespace Calculator{
    class TokensStream{
    public:
        TokensStream(std::string line);
        Token get();
    private:
        std::stringstream strm;
    };
}

#endif