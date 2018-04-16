#ifndef GRAMMAR_PARSER_H_
#define GRAMMAR_PARSER_H_

/*

GRAMMAR

Expression :=
    Term |                                     (12)
    Expression + Term |                        (11)
    Expression - Term                          (10)

Term :=
    Factor |                                   (9)
    Term / Factor |                            (8)
    Term * Factor                              (7)

Factor :=
    Floating_point_number |                    (6)
    (Expression) |                             (5)
    unary_function(Expression) |               (4)
    binary_function(Expression, Expression) |  (3)
    -Factor |                                  (2)
    +Factor                                    (1)
    
*/

#include "../Parser/Parser.h"

namespace Calculator{
    class GrammarParser{
    public:
        GrammarParser(Parser parser);

        double evaluate();
    private:
        double Expression();
        double Term();
        double Factor();
        Parser parser;
    };
}

#endif