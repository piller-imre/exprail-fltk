#include "Tokenizer.h"

#include <cctype>

Token Tokenizer::getNextToken(std::istream& stream)
{
    Token token;
    char c;

    while (true) {
        if (stream.get(c)) {
            if (std::isalpha(c)) {
                std::string keyword = readKeyword(stream);
                token.type = TokenType::KEYWORD;
                token.value = keyword;
                break;
            }
            else if (std::isdigit(c)) {
                std::string number = readNumber(stream);
                token.type = TokenType::NUMBER;
                token.value = number;
                break;
            }
            else if (c == '"') {
                std::string text = readText(stream);
                token.type = TokenType::TEXT;
                token.value = text;
                break;
            }
            else if (c == '\n') {
                token.type = TokenType::NEWLINE;
                token.value = "";
                break;
            }
        }
        else {
            token.type = TokenType::EMPTY;
            token.value = "";
            break;
        }
    }

    return token;
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
