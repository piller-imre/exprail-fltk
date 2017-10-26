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

std::ostream& operator<<(std::ostream& outputStream, TokenType tokenType)
{
    switch (tokenType) {
    case TokenType::KEYWORD:
        outputStream << "keyword";
        break;
    case TokenType::NUMBER:
        outputStream << "number";
        break;
    case TokenType::TEXT:
        outputStream << "text";
        break;
    case TokenType::NEWLINE:
        outputStream << "newline";
        break;
    case TokenType::EMPTY:
        outputStream << "empty";
        break;
    }

    return outputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Token& token)
{
    outputStream << "<" << token.getType() << ", '" << token.getValue() << "'>";
    return outputStream;
}
