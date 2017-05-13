#include "Tokenizer.h"

#include <cctype>

Token Tokenizer::getNextToken(std::istream& stream)
{
    char c;

    while (true) {
        if (stream.get(c)) {
            if (std::isalpha(c)) {
                std::string keyword = readKeyword(stream);
                return Token(TokenType::KEYWORD, keyword);
            }
            else if (std::isdigit(c)) {
                std::string number = readNumber(stream);
                return Token(TokenType::NUMBER, number);
            }
            else if (c == '"') {
                std::string text = readText(stream);
                return Token(TokenType::TEXT, text);
            }
            else if (c == '\n') {
                return Token(TokenType::NEWLINE, "");
            }
        }
        else {
            return Token(TokenType::EMPTY, "");
        }
    }
}

std::string Tokenizer::readKeyword(std::istream& stream)
{
    std::string keyword;
    char c;

    stream.unget();
    while (stream.get(c)) {
        if (std::isalnum(c)) {
            keyword += c;
        }
        else {
            stream.unget();
            return keyword;
        }
    }

    return keyword;
}

std::string Tokenizer::readNumber(std::istream& stream)
{
    std::string number;
    char c;

    stream.unget();
    while (stream.get(c)) {
        if (std::isdigit(c)) {
            number += c;
        }
        else {
            stream.unget();
            return number;
        }
    }

    return number;
}

std::string Tokenizer::readText(std::istream& stream)
{
    std::string text;
    char c;

    while (stream.get(c)) {
        if (c != '"') {
            text += c;
        }
        else {
            return text;
        }
    }

    return text;
}
