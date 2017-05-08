#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <istream>
#include <string>

/**
 * Possible graph description language tokens
 */
enum class TokenType
{
    KEYWORD,
    NUMBER,
    TEXT,
    NEWLINE,
    EMPTY
};

/**
 * Represents a graph description language token
 *
 * TODO: Use Token class instead!
 */
struct Token
{
    /**
     * The type of the token
     */
    TokenType type;

    /**
     * The value of the token
     */
    std::string value;
};

/**
 * Tokenizer for the graph description language
 */
class Tokenizer
{
public:

    /**
     * Get the next token from the stream.
     */
    static Token getNextToken(std::istream& stream);

protected:

    /**
     * Read a keyword from the stream.
     */
    static std::string readKeyword(std::istream& stream);

    /**
     * Read an integer number from the stream.
     */
    static std::string readNumber(std::istream& stream);

    /**
     * Read a quoted string as text from the stream.
     */
    static std::string readText(std::istream& stream);
};

#endif /* TOKENIZER_H */

