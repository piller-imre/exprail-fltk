#include "Parser.h"
#include "Tokenizer.h"

#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>

// TODO: Create test for calculating node types!
// TODO: Create test for checking last node id after parsing!

TEST(Parser_test, ExpressionName)
{
    std::istringstream input("expression \"name\"");
    Token token = Tokenizer::getNextToken(input);
    std::string expressionName = Parser::readExpressionName(input, token);
    ASSERT_EQ(expressionName, "name");
    ASSERT_EQ(token.getType(), TokenType::EMPTY);
}

TEST(Parser_test, NodesAfterExpressionName)
{
    std::istringstream input("expression \"name\"\nnodes");
    Token token = Tokenizer::getNextToken(input);
    std::string expressionName = Parser::readExpressionName(input, token);
    ASSERT_EQ(expressionName, "name");
    ASSERT_EQ(token.getType(), TokenType::KEYWORD);
    ASSERT_EQ(token.getValue(), "nodes");
}

TEST(Parser_test, SingleNode)
{
    std::istringstream input("nodes\n1 start \"name\" 30 -20");
    Token token = Tokenizer::getNextToken(input);
    std::map<int, Node> nodes = Parser::readNodes(input, token);
    ASSERT_EQ(nodes.size(), 1);
    ASSERT_NE(nodes.find(1), nodes.end());
    ASSERT_EQ(nodes[1].getType(), NodeType::START);
    ASSERT_EQ(nodes[1].getValue(), "name");
    ASSERT_EQ(nodes[1].getPosition().getX(), 30);
    ASSERT_EQ(nodes[1].getPosition().getY(), -20);
    ASSERT_EQ(token.getType(), TokenType::EMPTY);
}

TEST(Parser_test, MultipleNodes)
{
    std::istringstream input("nodes\n1 start \"a\" 30 -20\n2 finish \"b\" -10 40");
    Token token = Tokenizer::getNextToken(input);
    std::map<int, Node> nodes = Parser::readNodes(input, token);
    ASSERT_EQ(nodes.size(), 2);
    ASSERT_NE(nodes.find(1), nodes.end());
    ASSERT_EQ(nodes[1].getType(), NodeType::START);
    ASSERT_EQ(nodes[1].getValue(), "a");
    ASSERT_EQ(nodes[1].getPosition().getX(), 30);
    ASSERT_EQ(nodes[1].getPosition().getY(), -20);
    ASSERT_NE(nodes.find(2), nodes.end());
    ASSERT_EQ(nodes[2].getType(), NodeType::FINISH);
    ASSERT_EQ(nodes[2].getValue(), "b");
    ASSERT_EQ(nodes[2].getPosition().getX(), -10);
    ASSERT_EQ(nodes[2].getPosition().getY(), 40);
    ASSERT_EQ(token.getType(), TokenType::EMPTY);
}

TEST(Parser_test, SingleEdge)
{
    std::istringstream input("edges\n1 2");
    Token token = Tokenizer::getNextToken(input);
    std::set<Edge> edges = Parser::readEdges(input, token);
    ASSERT_EQ(edges.size(), 1);
    ASSERT_NE(edges.find(Edge(1, 2)), edges.end());
    ASSERT_EQ(token.getType(), TokenType::EMPTY);
}

TEST(Parser_test, MultipleEdges)
{
    std::istringstream input("edges\n1 2\n3 4\n5 6");
    Token token = Tokenizer::getNextToken(input);
    std::set<Edge> edges = Parser::readEdges(input, token);
    ASSERT_EQ(edges.size(), 3);
    ASSERT_NE(edges.find(Edge(1, 2)), edges.end());
    ASSERT_NE(edges.find(Edge(3, 4)), edges.end());
    ASSERT_NE(edges.find(Edge(5, 6)), edges.end());
    ASSERT_EQ(token.getType(), TokenType::EMPTY);
}

TEST(Parser_test, ExpressionNameSkipEmptyLines)
{
    std::istringstream input("expression \"name\"\n\n\nnodes");
    Token token = Tokenizer::getNextToken(input);
    Parser::readExpressionName(input, token);
    ASSERT_EQ(token.getType(), TokenType::KEYWORD);
    ASSERT_EQ(token.getValue(), "nodes");
}

TEST(Parser_test, NodesSkipEmptyLines)
{
    std::istringstream input("nodes\n1 start \"a\" 30 -20\n2 finish \"b\" -10 40\n\n\nedges");
    Token token = Tokenizer::getNextToken(input);
    Parser::readNodes(input, token);
    ASSERT_EQ(token.getType(), TokenType::KEYWORD);
    ASSERT_EQ(token.getValue(), "edges");
}

TEST(Parser_test, EdgesSkipEmptyLines)
{
    std::istringstream input("edges\n1 2\n3 4\n5 6\n\n\n\nexpression");
    Token token = Tokenizer::getNextToken(input);
    Parser::readEdges(input, token);
    ASSERT_EQ(token.getType(), TokenType::KEYWORD);
    ASSERT_EQ(token.getValue(), "expression");
}

TEST(Parser_test, EdgesSkipLastEmptyLines)
{
    std::istringstream input("edges\n1 2\n3 4\n5 6\n\n\n\n");
    Token token = Tokenizer::getNextToken(input);
    Parser::readEdges(input, token);
    ASSERT_EQ(token.getType(), TokenType::EMPTY);
    ASSERT_EQ(token.getValue(), "");
}

TEST(Parser_test, SingleGrammar)
{
    std::istringstream input(
        "expression \"sample\"\n"
        "nodes\n"
        "1 start \"a\" 30 -20\n"
        "2 finish \"b\" -10 40\n"
        "3 token \"c\" 50 0\n"
        "edges\n"
        "1 2\n"
        "1 3\n"
        "3 2\n"
    );
    Grammar grammar = Parser::readGrammar(input);
    // TODO: Check that the expression name is exists!
    Expression expression = grammar.getExpression("sample");
    std::map<int, Node> nodes = expression.getNodes();
    std::set<Edge> edges = expression.getEdges();

    ASSERT_EQ(nodes.size(), 3);
    ASSERT_EQ(edges.size(), 3);
    ASSERT_NE(nodes.find(1), nodes.end());
    ASSERT_NE(nodes.find(2), nodes.end());
    ASSERT_NE(nodes.find(3), nodes.end());
    ASSERT_NE(edges.find(Edge(1, 2)), edges.end());
    ASSERT_NE(edges.find(Edge(1, 3)), edges.end());
    ASSERT_NE(edges.find(Edge(3, 2)), edges.end());

    ASSERT_EQ(nodes[1].getType(), NodeType::START);
    ASSERT_EQ(nodes[1].getValue(), "a");
    ASSERT_EQ(nodes[1].getPosition().getX(), 30);
    ASSERT_EQ(nodes[1].getPosition().getY(), -20);

    ASSERT_EQ(nodes[2].getType(), NodeType::FINISH);
    ASSERT_EQ(nodes[2].getValue(), "b");
    ASSERT_EQ(nodes[2].getPosition().getX(), -10);
    ASSERT_EQ(nodes[2].getPosition().getY(), 40);

    ASSERT_EQ(nodes[3].getType(), NodeType::TOKEN);
    ASSERT_EQ(nodes[3].getValue(), "c");
    ASSERT_EQ(nodes[3].getPosition().getX(), 50);
    ASSERT_EQ(nodes[3].getPosition().getY(), 0);
}
