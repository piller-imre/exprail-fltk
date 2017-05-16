#include "Parser.h"

#include "Tokenizer.h"

Grammar Parser::readGrammar(std::istream& stream)
{
    Token token;
    Grammar grammar;

    token = Tokenizer::getNextToken(stream);
    while (token.getType() != TokenType::EMPTY) {
        std::string expressionName = readExpressionName(stream, token);
        std::map<int, Node> nodes = readNodes(stream, token);
        std::set<Edge> edges = readEdges(stream, token);
        Expression expression(nodes, edges);
        grammar.addExpression(expressionName, expression);
    }

    return grammar;
}

std::string Parser::readExpressionName(std::istream& stream, Token& token)
{
    std::string keyword = readKeyword(stream, token);
    if (keyword != "expression") {
        throw std::runtime_error("An 'expression' keyword has expected!");
    }

    std::string expressionName = readText(stream, token);
    skipEmptyLines(stream, token);

    return expressionName;
}

std::map<int, Node> Parser::readNodes(std::istream& stream, Token& token)
{
    std::map<int, Node> nodes;

    std::string keyword = readKeyword(stream, token);
    if (keyword != "nodes") {
        throw std::runtime_error("A 'nodes' keyword has expected!");
    }

    skipEmptyLines(stream, token);

    while (token.getType() == TokenType::NUMBER) {
        int id = readNumber(stream, token);
        std::string type = readKeyword(stream, token);
        std::string value = readText(stream, token);
        int x = readNumber(stream, token);
        int y = readNumber(stream, token);
        skipEmptyLines(stream, token);
        // TODO: Use valid node types!
        if (type == "begin") {
            nodes[id] = Node(NodeType::BEGIN, value, Point(x, y));
        }
        else if (type == "end") {
            nodes[id] = Node(NodeType::END, value, Point(x, y));
        }
        else if (type == "keyword") {
            nodes[id] = Node(NodeType::KEYWORD, value, Point(x, y));
        }
    }

    return nodes;
}

std::set<Edge> Parser::readEdges(std::istream& stream, Token& token)
{
    std::set<Edge> edges;

    std::string keyword = readKeyword(stream, token);
    if (keyword != "edges") {
        throw std::runtime_error("An 'edges' keyword has expected!");
    }

    skipEmptyLines(stream, token);

    while (token.getType() == TokenType::NUMBER) {
        int sourceId = readNumber(stream, token);
        int targetId = readNumber(stream, token);
        skipEmptyLines(stream, token);
        edges.insert(Edge(sourceId, targetId));
    }

    return edges;
}

std::string Parser::readKeyword(std::istream& stream, Token& token)
{
    if (token.getType() != TokenType::KEYWORD) {
        throw std::runtime_error("Keyword token has expected!");
    }

    std::string keyword = token.getValue();
    token = Tokenizer::getNextToken(stream);

    return keyword;
}

int Parser::readNumber(std::istream& stream, Token& token)
{
    if (token.getType() != TokenType::NUMBER) {
        throw std::runtime_error("Number token has expected!");
    }

    int number = std::stoi(token.getValue());
    token = Tokenizer::getNextToken(stream);

    return number;
}

std::string Parser::readText(std::istream& stream, Token& token)
{
    if (token.getType() != TokenType::TEXT) {
        throw std::runtime_error("Text token has expected!");
    }

    std::string text = token.getValue();
    token = Tokenizer::getNextToken(stream);

    return text;
}

void Parser::skipEmptyLines(std::istream& stream, Token& token)
{
    while (token.getType() == TokenType::NEWLINE) {
        token = Tokenizer::getNextToken(stream);
    }
}
