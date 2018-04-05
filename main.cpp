#include <iostream>
#include <string>
#include <exception>

#include "Tokens/Tokens.h"
#include "TokensParser/TokensParser.h"
#include "ShuntingYard/ShuntingYard.h"
#include "Rpn/Rpn.h"

using namespace Calculator;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main(){
    string line;

    while(getline(cin, line)){
        try{
            cout << Rpn::evaluate(
                ShuntingYard::transformToRpn(
                    TokensParser(line).parse()
                )
            ) << endl;       
        }
        catch(const std::exception &e){
            cout << "The following exception occured: ";
            cout << e.what() << endl;
        }
    }

    return 0;
}