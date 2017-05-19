#include "Edge.h"
#include "Expression.h"
#include "Grammar.h"
#include "Node.h"

#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>

TEST(Serialization_test, DefaultNode)
{
    std::stringstream output;
    Node node;
    output << node;
    ASSERT_EQ(output.str(), "start \"\" 0 0");
}

TEST(Serialization_test, CustomNode)
{
    std::stringstream output;
    Node node(NodeType::TOKEN, "keyword:if", Point(-20, 30));
    output << node;
    ASSERT_EQ(output.str(), "token \"keyword:if\" -20 30");
}

TEST(Serialization_test, QuotedValuedNode)
{
    std::stringstream output;
    Node node(NodeType::INFO, "Print \"something\"", Point(4, -5));
    output << node;
    ASSERT_EQ(output.str(), "info \"Print \\\"something\\\"\" 4 -5");
}

TEST(Serialization_test, BackslashValuedNode)
{
    std::stringstream output;
    Node node(NodeType::ERROR, "Unexpected \\ character!", Point(5, 10));
    output << node;
    ASSERT_EQ(output.str(), "error \"Unexpected \\\\ character!\" 5 10");
}

TEST(Serialization_test, Edge)
{
    std::stringstream output;
    Edge edge(6, 8);
    output << edge;
    ASSERT_EQ(output.str(), "6 8");
}

TEST(Serialization_test, EmptyExpression)
{
    std::stringstream output;
    Expression expression;
    output << expression;
    ASSERT_EQ(output.str(), "nodes\nedges\n");
}

TEST(Serialization_test, SimpleExpression)
{
    std::stringstream output;
    Expression expression;
    expression.addNode(Node(NodeType::START, "entry", Point(-10, 0)));
    expression.addNode(Node(NodeType::FINISH, "exit", Point(10, 0)));
    expression.addNode(Node(NodeType::TOKEN, "keyword", Point(0, 10)));
    expression.addEdge(1, 2);
    expression.addEdge(1, 3);
    expression.addEdge(3, 2);
    output << expression;
    std::string expectedResult =
        "nodes\n"
        "1 start \"entry\" -10 0\n"
        "2 finish \"exit\" 10 0\n"
        "3 token \"keyword\" 0 10\n"
        "edges\n"
        "1 2\n"
        "1 3\n"
        "3 2\n";
    ASSERT_EQ(output.str(), expectedResult);
}

TEST(Serialization_test, EmptyGrammar)
{
    std::stringstream output;
    Grammar grammar;
    output << grammar;
    ASSERT_EQ(output.str(), "");
}

TEST(Serialization_test, SimpleGrammar)
{
    std::stringstream output;
    Grammar grammar;

    Expression a;
    a.addNode(Node(NodeType::START, "entry", Point(-10, 0)));
    a.addNode(Node(NodeType::FINISH, "exit", Point(10, 0)));
    a.addNode(Node(NodeType::TOKEN, "keyword", Point(0, 10)));
    a.addEdge(1, 2);
    a.addEdge(1, 3);
    a.addEdge(3, 2);
    grammar.addExpression("A", a);

    Expression b;
    b.addNode(Node(NodeType::START, "", Point(30, 0)));
    b.addNode(Node(NodeType::FINISH, "", Point(40, 0)));
    b.addNode(Node(NodeType::TOKEN, "keyword", Point(0, -10)));
    b.addNode(Node(NodeType::ERROR, "Unexpected error!", Point(20, 20)));
    b.addEdge(1, 2);
    b.addEdge(1, 3);
    b.addEdge(3, 2);
    b.addEdge(1, 4);
    grammar.addExpression("B", b);

    std::string expectedResult =
        "expression \"A\"\n"
        "nodes\n"
        "1 start \"entry\" -10 0\n"
        "2 finish \"exit\" 10 0\n"
        "3 token \"keyword\" 0 10\n"
        "edges\n"
        "1 2\n"
        "1 3\n"
        "3 2\n"
        "\n"
        "expression \"B\"\n"
        "nodes\n"
        "1 start \"\" 30 0\n"
        "2 finish \"\" 40 0\n"
        "3 token \"keyword\" 0 -10\n"
        "4 error \"Unexpected error!\" 20 20\n"
        "edges\n"
        "1 2\n"
        "1 3\n"
        "1 4\n"
        "3 2\n"
        "\n";

    output << grammar;
    ASSERT_EQ(output.str(), expectedResult);
}
