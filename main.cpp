#include <vector>
#include <string>

#include "Tokens/Tokens.h"
#include "TokensParser/TokensParser.h"

using namespace Calculator;
using std::vector;

int main(){
    TokensParser parser("2 + 2*(4 - 2^3)");

    vector<Token> v = parser.parse();

    return 0;
}