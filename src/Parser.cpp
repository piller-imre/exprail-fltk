#include "Parser.h"

#include "Tokenizer.h"

#include <sstream>

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
        expression.updateLastNodeId();
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
        nodes[id] = Node(calcNodeType(type), value, Point(x, y));
    }

    return nodes;
}

NodeType Parser::calcNodeType(const std::string& value)
{
    std::map<std::string, NodeType> table = {
        {"start", NodeType::START},
        {"finish", NodeType::FINISH},
        {"connection", NodeType::CONNECTION},
        {"expression", NodeType::EXPRESSION},
        {"ground", NodeType::GROUND},
        {"token", NodeType::TOKEN},
        {"except_token", NodeType::EXCEPT_TOKEN},
        {"default_token", NodeType::DEFAULT_TOKEN},
        {"router", NodeType::ROUTER},
        {"except_router", NodeType::EXCEPT_ROUTER},
        {"default_router", NodeType::DEFAULT_ROUTER},
        {"info", NodeType::INFO},
        {"error", NodeType::ERROR},
        {"operation", NodeType::OPERATION},
        {"transformation", NodeType::TRANSFORMATION},
        {"stack", NodeType::STACK},
        {"clean", NodeType::CLEAN}
    };
    if (table.find(value) != table.end()) {
        return table.at(value);
    }
    else {
        std::stringstream message;
        message << "The '" << value << "' is an invalid node type!";
        throw std::runtime_error(message.str());
    }
}

std::set<Edge> Parser::readEdges(std::istream& stream, Token& token)
{
    std::set<Edge> edges;

    std::string keyword = readKeyword(stream, token);
    if (keyword != "edges") {
        std::stringstream message;
        message << "An 'edges' keyword has expected instead of " << token << "!";
        throw std::runtime_error(message.str());
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
        std::stringstream message;
        message << "Keyword token has expected instead of " << token << "!";
        throw std::runtime_error(message.str());
    }

    std::string keyword = token.getValue();
    token = Tokenizer::getNextToken(stream);

    return keyword;
}

int Parser::readNumber(std::istream& stream, Token& token)
{
    if (token.getType() != TokenType::NUMBER) {
        std::stringstream message;
        message << "Number token has expected instead of " << token << "!";
        throw std::runtime_error(message.str());
    }

    int number = std::stoi(token.getValue());
    token = Tokenizer::getNextToken(stream);

    return number;
}

std::string Parser::readText(std::istream& stream, Token& token)
{
    if (token.getType() != TokenType::TEXT) {
        std::stringstream message;
        message << "Text token has expected instead of " << token << "!";
        throw std::runtime_error(message.str());
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
