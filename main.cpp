#include <iostream>
#include <string>
#include <exception>

#include "Parser/Parser.h"
#include "GrammarParser/GrammarParser.h"

using namespace Calculator;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::exception;

int main(){
    string line;

    while(getline(cin, line)){
        try{
            cout << GrammarParser(Parser(line)).evaluate() << endl;
        }
        catch(const exception &e){
            cout << "The following exception occured: ";
            cout << e.what() << endl;
        }
    }
}