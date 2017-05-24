#include "Grammar.h"

#include <gtest/gtest.h>

TEST(Grammar_test, EmptyGrammar)
{
    Grammar grammar;
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 0);
}

TEST(Grammar_test, SingleExpressionGrammar)
{
    Grammar grammar;
    grammar.addExpression("single", Expression());
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 1);
    ASSERT_EQ(expressionOrder[0], "single");
}

TEST(Grammar_test, ThreeExpressionGrammar)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.addExpression("second", Expression());
    grammar.addExpression("third", Expression());
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 3);
    ASSERT_EQ(expressionOrder[0], "first");
    ASSERT_EQ(expressionOrder[1], "second");
    ASSERT_EQ(expressionOrder[2], "third");
}

TEST(Grammar_test, MoveSingleExpressionDown)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.moveExpressionDown("first");
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 1);
    ASSERT_EQ(expressionOrder[0], "first");
}

TEST(Grammar_test, MoveSingleExpressionUp)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.moveExpressionUp("first");
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 1);
    ASSERT_EQ(expressionOrder[0], "first");
}

TEST(Grammar_test, MoveExpressionDown)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.addExpression("second", Expression());
    grammar.addExpression("third", Expression());
    std::vector<std::string> expressionOrder;
    grammar.moveExpressionUp("first");
    expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 3);
    ASSERT_EQ(expressionOrder[0], "second");
    ASSERT_EQ(expressionOrder[1], "first");
    ASSERT_EQ(expressionOrder[2], "third");
    grammar.moveExpressionUp("first");
    expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 3);
    ASSERT_EQ(expressionOrder[0], "second");
    ASSERT_EQ(expressionOrder[1], "third");
    ASSERT_EQ(expressionOrder[2], "first");
}

TEST(Grammar_test, MoveExpressionUp)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.addExpression("second", Expression());
    grammar.addExpression("third", Expression());
    std::vector<std::string> expressionOrder;
    grammar.moveExpressionUp("second");
    expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 3);
    ASSERT_EQ(expressionOrder[0], "second");
    ASSERT_EQ(expressionOrder[1], "first");
    ASSERT_EQ(expressionOrder[2], "third");
    grammar.moveExpressionUp("third");
    expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 3);
    ASSERT_EQ(expressionOrder[0], "second");
    ASSERT_EQ(expressionOrder[1], "third");
    ASSERT_EQ(expressionOrder[2], "first");
}

TEST(Grammar_test, MoveMissingExpressionDown)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    try {
        grammar.moveExpressionDown("second");
    }
    catch (const std::runtime_error& error) {
        ASSERT_STREQ(error.what(), "The expression 'second' is missing!");
    }
    catch (...) {
        FAIL() << "Unexpected exception type!";
    }
}

TEST(Grammar_test, MoveMissingExpressionUp)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    try {
        grammar.moveExpressionUp("second");
    }
    catch (const std::runtime_error& error) {
        ASSERT_STREQ(error.what(), "The expression 'second' is missing!");
    }
    catch (...) {
        FAIL() << "Unexpected exception type!";
    }
}

TEST(Grammar_test, RenamingInExpressionOrder)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.addExpression("second", Expression());
    grammar.addExpression("third", Expression());
    grammar.renameExpression("third", "last");
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 3);
    ASSERT_EQ(expressionOrder[0], "first");
    ASSERT_EQ(expressionOrder[1], "second");
    ASSERT_EQ(expressionOrder[2], "last");
}

TEST(Grammar_test, RemoveFromExpressionOrder)
{
    Grammar grammar;
    grammar.addExpression("first", Expression());
    grammar.addExpression("second", Expression());
    grammar.addExpression("third", Expression());
    grammar.removeExpression("first");
    grammar.removeExpression("third");
    std::vector<std::string> expressionOrder = grammar.getExpressionOrder();
    ASSERT_EQ(expressionOrder.size(), 1);
    ASSERT_EQ(expressionOrder[0], "second");
}
