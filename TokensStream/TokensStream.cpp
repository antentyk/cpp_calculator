#include "TokensStream.h"

using namespace Calculator;

TokensStream::TokensStream(std::string line):
    strm(std::stringstream(prepare(line)))
{}

std::string TokensStream::prepare(std::string line){
    // знаю, що тягнути boost заради декількох рядочків не варто,
    // але треба колись його таки почати вчити =)

    // replacing sin and cos with s and c for easier parsing
    boost::algorithm::replace_all(
        line,
        "sin",
        std::string(1, kReversedCharRepresentation.at(TokenType::Sine))
    );
    boost::algorithm::replace_all(
        line,
        "cos",
        std::string(1, kReversedCharRepresentation.at(TokenType::Cosine))
    );

    // replacing max and min with a and i for easier parsing
    boost::algorithm::replace_all(
        line,
        "max",
        std::string(1, kReversedCharRepresentation.at(TokenType::Max))
    );
    boost::algorithm::replace_all(
        line,
        "min",
        std::string(1, kReversedCharRepresentation.at(TokenType::Min))
    );

    // eliminating cases like sin(0, 1) + by putting extra + 0 to the end
    line += " + 0";
    
    return line;
}

Token TokensStream::get(){
    char current;

    strm >> current;
    if(strm.fail())
        throw NoTokensLeft();
    
    auto itr = kCharRepresentation.find(current);
    if(itr != kCharRepresentation.end())
        return Token(itr->second);
    
    strm.putback(current);

    double value;
    strm >> value;

    if(strm.fail())
        throw InvalidToken();
    
    return Token(TokenType::Number, value);
}