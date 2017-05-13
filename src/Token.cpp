#include "Token.h"

Token::Token()
{
    _type = TokenType::EMPTY;
    _value = "";
}

Token::Token(TokenType type, const std::string& value)
{
    _type = type;
    _value = value;
}

TokenType Token::getType() const
{
    return _type;
}

std::string Token::getValue() const
{
    return _value;
}
