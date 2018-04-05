#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace Calculator{
    class NumberTokenInitialization : public std::exception{
    public:
        const char * what () const throw (){
            return "Number token should be provided with double value";
        }
    };

    class NonNumberTokenInitialization : public std::exception{
    public:
        const char * what () const throw (){
            return "Only number token can have double value";
        }
    };

    class TokenConvertion : public std::exception{
    public:
        const char * what () const throw (){
            return "This token cannot be converted to double";
        }
    };

    class PrecedenceError : public std::exception{
    public:
        const char * what () const throw (){
            return "This token cannot have precedence";
        }
    };

    class NoTokensLeft : public std::exception{
    public:
        const char * what () const throw (){
            return "There are no tokens left";
        }
    };

    class InvalidToken : public std::exception{
    public:
        const char * what () const throw (){
            return "Invalid token detected";
        }
    };

    class MismatchedBrackets : public std::exception{
    public:
        const char * what () const throw (){
            return "Invalid use of brackets";
        }
    };

    class InvalidOperand : public std::exception{
    public:
        const char * what () const throw (){
            return "Too few operands provided or operands has wrong type";
        }
    };
}

#endif