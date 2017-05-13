#include "Tokenizer.h"

#include <gtest/gtest.h>

#include <sstream>

TEST(Tokenizer_test, EmptyInput)
{
    std::istringstream input;
    Token token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, InfiniteEmptyToken)
{
    std::istringstream input;
    Token token;
    for (int i = 0; i < 10; ++i) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.getType(), TokenType::EMPTY);
        EXPECT_EQ(token.getValue(), "");
    }
}

TEST(Tokenizer_test, SingleKeyword)
{
    Token token;
    std::istringstream input("keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::KEYWORD);
    EXPECT_EQ(token.getValue(), "keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, MultipleKeywords)
{
    Token token;
    std::istringstream input("first second third");
    std::vector<std::string> values = {"first", "second", "third"};
    for (const std::string& value : values) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.getType(), TokenType::KEYWORD);
        EXPECT_EQ(token.getValue(), value);
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, SingleNumber)
{
    Token token;
    std::istringstream input("1");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::NUMBER);
    EXPECT_EQ(token.getValue(), "1");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, MultipleNumbers)
{
    Token token;
    std::istringstream input("1 2 3 4 5");
    std::vector<std::string> values = {"1", "2", "3", "4", "5"};
    for (const std::string& value : values) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.getType(), TokenType::NUMBER);
        EXPECT_EQ(token.getValue(), value);
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, SingleText)
{
    Token token;
    std::istringstream input("\"alpha\"");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::TEXT);
    EXPECT_EQ(token.getValue(), "alpha");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, MultipleTexts)
{
    Token token;
    std::istringstream input("\"alpha\" \"beta\" \"gamma\"");
    std::vector<std::string> values = {"alpha", "beta", "gamma"};
    for (const std::string& value : values) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.getType(), TokenType::TEXT);
        EXPECT_EQ(token.getValue(), value);
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, SingleNewline)
{
    Token token;
    std::istringstream input("\n");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::NEWLINE);
    EXPECT_EQ(token.getValue(), "");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, MultipleNewlines)
{
    Token token;
    std::istringstream input("\n\n\n\n\n\n");
    for (int i = 0; i < 6; ++i) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.getType(), TokenType::NEWLINE);
        EXPECT_EQ(token.getValue(), "");
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, AllTokenTypeAtOnce)
{
    Token token;
    std::istringstream input("keyword 1234 \"text\"\n");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::KEYWORD);
    EXPECT_EQ(token.getValue(), "keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::NUMBER);
    EXPECT_EQ(token.getValue(), "1234");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::TEXT);
    EXPECT_EQ(token.getValue(), "text");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::NEWLINE);
    EXPECT_EQ(token.getValue(), "");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}

TEST(Tokenizer_test, IgnoreWhitespaces)
{
    Token token;
    std::istringstream input("\t   keyword\t1234 \"text\"   \n ");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::KEYWORD);
    EXPECT_EQ(token.getValue(), "keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::NUMBER);
    EXPECT_EQ(token.getValue(), "1234");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::TEXT);
    EXPECT_EQ(token.getValue(), "text");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::NEWLINE);
    EXPECT_EQ(token.getValue(), "");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.getType(), TokenType::EMPTY);
    EXPECT_EQ(token.getValue(), "");
}
