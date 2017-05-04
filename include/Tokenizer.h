#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

/**
 * Possible graph description language tokens
 */
enum class TokenType
{
    KEYWORD,
    STRING,
    INTEGER,
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
     * Construct a tokenizer for the given file.
     */
    Tokenizer(const std::string& filename);

    /**
     * Get the next token of the input file.
     */
    Token getNextToken();

protected:

    /**
     * Open the file for tokenization.
     */
    void openFile(const std::string& filename);
};

#endif /* TOKENIZER_H */

