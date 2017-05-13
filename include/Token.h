#ifndef TOKEN_H
#define TOKEN_H

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
 */
class Token
{
public:

    /**
     * Construct an empty token.
     */
    Token();

    /**
     * Constructs new token.
     */
    Token(TokenType type, const std::string& value);

    /**
     * Get the type of the token.
     */
    TokenType getType() const;

    /**
     * Get the value of the token.
     */
    std::string getValue() const;

private:

    /**
     * The type of the token
     */
    TokenType _type;

    /**
     * The value of the token
     */
    std::string _value;
};

#endif /* TOKEN_H */
