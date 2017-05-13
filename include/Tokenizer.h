#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Token.h"

#include <istream>
#include <string>

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

