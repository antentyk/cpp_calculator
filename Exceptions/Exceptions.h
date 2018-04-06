#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace Calculator{
    class NoGrammarRule : public std::exception{
    public:
        const char * what() const throw (){
            return "No suitable grammar rule";
        }
    };

    class NoValue : public std::exception{
    public:
        const char * what() const throw (){
            return "This token cannot have value";
        }
    };

    class TokenInitialization : public std::exception{
    public:
        const char * what() const throw() {
            return "You should use another constructor for this token";
        }
    };

    class InvalidToken : public std::exception{
    public:
        const char * what() const throw(){
            return "Invalid token detected";
        }
    };

    class NoTokensLeft : public std::exception{
    public:
        const char * what() const throw (){
            return "There are no tokens left";
        }
    };

    class NoRevertTokens : public std::exception{
    public:
        const char * what() const throw(){
            return "There are no tokens to revert";
        }
    };

    class ExpressionFailure : public std::exception{
    public:
        const char * what() const throw(){
            return "Error while parsing Expression";
        }
    };

    class TermFailure : public std::exception{
    public:
        const char * what() const throw(){
            return "Error while parsing Term";
        }
    };

    class FactorFailure : public std::exception{
    public:
        const char * what() const throw(){
            return "Error while parsing Factor";
        }
    };

    class OddTokensLeft : public std::exception{
    public:
        const char * what() const throw(){
            return "There are tokens that cannot be parsed";
        }
    };
}

#endif