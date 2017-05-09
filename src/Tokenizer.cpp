#include "Tokenizer.h"

Token Tokenizer::getNextToken(std::istream& stream)
{
    Token token;
    // TODO: Get the next token!
    token.type = TokenType::EMPTY;
    token.value = "";
    return token;
}

static std::string readKeyword(std::istream& stream)
{
    std::string keyword;
    // TODO: Read the keyword!
    return keyword;
}

static std::string readNumber(std::istream& stream)
{
    std::string number;
    // TODO: Read the number!
    return number;
}

static std::string readText(std::istream& stream)
{
    std::string text;
    // TODO: Read the text!
    return text;
}

