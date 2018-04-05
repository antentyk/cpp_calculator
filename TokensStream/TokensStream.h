#ifndef TOKENS_STREAM_H_
#define TOKENS_STREAM_H_

#include <string>
#include <sstream>

#include <boost/algorithm/string.hpp>

#include "../Tokens/Tokens.h"
#include "../Exceptions/Exceptions.h"

namespace Calculator{
    class TokensStream{
    public:
        TokensStream(std::string line);
        Token get();
    private:
        static std::string prepare(std::string line);

        std::stringstream strm;
    };
}

#endif