#include "Parser.h"

#include "Tokenizer.h"

Grammar Parser::readGrammar(std::istream& stream)
{
    Token token;
    Grammar grammar;

    // TODO: Skip the empty lines!
    token = Tokenizer::getNextToken(stream);
    while (token.getType() != TokenType::EMPTY) {
        std::string expressionName;
        std::map<int, Node> nodes;
        std::set<Edge> edges;
        if (token.getType() == TokenType::KEYWORD && token.getValue() == "expression") {
            expressionName = readExpressionName(stream, token);
        }
        if (token.getType() == TokenType::KEYWORD && token.getValue() == "nodes") {
            nodes = readNodes(stream, token);
        }
        if (token.getType() == TokenType::KEYWORD && token.getValue() == "edges") {
            edges = readEdges(stream, token);
        }
        Expression expression(nodes, edges);
        grammar.addExpression(expressionName, expression);
    }

    return grammar;
}

std::string Parser::readExpressionName(std::istream& stream, Token& lastToken)
{
    std::string expressionName;
    // TODO: Read the expression name from the stream!
    return expressionName;
}

std::map<int, Node> Parser::readNodes(std::istream& stream, Token& lastToken)
{
    std::map<int, Node> nodes;
    // TODO: Read the nodes from the stream!
    return nodes;
}

std::set<Edge> Parser::readEdges(std::istream& stream, Token& lastToken)
{
    std::set<Edge> edges;
    // TODO: Read the edges from the stream!
    return edges;
}
