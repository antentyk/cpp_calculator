#ifndef GRAMMAR_PARSER_H_
#define GRAMMAR_PARSER_H_

/*

GRAMMAR

Expression :=
    Term + Expression |                                     (17)
    Term - Expression |                                     (16)
    unary_function(Expression) |                            (15)
    unary_function(Expression) + Expression |               (14)
    unary_function(Expression) - Expression |               (13)
    binary_function(Expression, Expression) |               (12)
    binary_function(Expression, Expression) + Expression |  (11)
    binary_function(Expression, Expression) - Expression |  (10)
    Term                                                    (9)
Term := 
    Factor * Term |                                         (8)
    Factor / Term |                                         (7)
    Factor ^ Term |                                         (6) 
    +Term |                                                 (5)
    -Term |                                                 (4)
    Factor                                                  (3)
Factor := 
    (Expression) |                                          (2)
    Float_number                                            (1)

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