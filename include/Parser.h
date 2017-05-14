#ifndef PARSER_H
#define PARSER_H

#include "Grammar.h"
#include "Token.h"

#include <istream>
#include <map>
#include <string>

/**
 * Parser for the graph description language
 */
class Parser
{
public:

    /**
     * Parse the input stream as a grammar description and build a grammar instance.
     */
    static Grammar readGrammar(std::istream& stream);

    /**
     * Read an expression name from the input stream.
     */
    static std::string readExpressionName(std::istream& stream, Token& lastToken);

    /**
     * Read node data from the input stream.
     */
    static std::map<int, Node> readNodes(std::istream& stream, Token& lastToken);

    /**
     * Read edge data from the input stream.
     */
    static std::set<Edge> readEdges(std::istream& stream, Token& lastToken);
};

#endif /* PARSER_H */
