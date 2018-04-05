#include <iostream>
#include <string>

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

    while(getline(cin, line))
        cout << Rpn::evaluate(
            ShuntingYard::transformToRpn(
                TokensParser(line).parse()
            )
        ) << endl;

    return 0;
}