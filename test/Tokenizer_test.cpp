#include "Tokenizer.h"

#include <gtest/gtest.h>

#include <sstream>

TEST(Tokenizer_test, EmptyInput)
{
    std::istringstream input;
    Token token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, InfiniteEmptyToken)
{
    std::istringstream input;
    Token token;
    for (int i = 0; i < 10; ++i) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.type, TokenType::EMPTY);
        EXPECT_EQ(token.value, "");
    }
}

TEST(Tokenizer_test, SingleKeyword)
{
    Token token;
    std::istringstream input("keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::KEYWORD);
    EXPECT_EQ(token.value, "keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, MultipleKeywords)
{
    Token token;
    std::istringstream input("first second third");
    std::vector<std::string> values = {"first", "second", "third"};
    for (const std::string& value : values) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.type, TokenType::KEYWORD);
        EXPECT_EQ(token.value, value);
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, SingleNumber)
{
    Token token;
    std::istringstream input("1");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::NUMBER);
    EXPECT_EQ(token.value, "1");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, MultipleNumbers)
{
    Token token;
    std::istringstream input("1 2 3 4 5");
    std::vector<std::string> values = {"1", "2", "3", "4", "5"};
    for (const std::string& value : values) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.type, TokenType::NUMBER);
        EXPECT_EQ(token.value, value);
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, SingleText)
{
    Token token;
    std::istringstream input("\"alpha\"");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::TEXT);
    EXPECT_EQ(token.value, "alpha");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, MultipleTexts)
{
    Token token;
    std::istringstream input("\"alpha\" \"beta\" \"gamma\"");
    std::vector<std::string> values = {"alpha", "beta", "gamma"};
    for (const std::string& value : values) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.type, TokenType::TEXT);
        EXPECT_EQ(token.value, value);
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, SingleNewline)
{
    Token token;
    std::istringstream input("\n");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::NEWLINE);
    EXPECT_EQ(token.value, "");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, MultipleNewlines)
{
    Token token;
    std::istringstream input("\n\n\n\n\n\n");
    for (int i = 0; i < 6; ++i) {
        token = Tokenizer::getNextToken(input);
        EXPECT_EQ(token.type, TokenType::NEWLINE);
        EXPECT_EQ(token.value, "");
    }
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, AllTokenTypeAtOnce)
{
    Token token;
    std::istringstream input("keyword 1234 \"text\"\n");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::KEYWORD);
    EXPECT_EQ(token.value, "keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::NUMBER);
    EXPECT_EQ(token.value, "1234");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::TEXT);
    EXPECT_EQ(token.value, "text");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::NEWLINE);
    EXPECT_EQ(token.value, "");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}

TEST(Tokenizer_test, IgnoreWhitespaces)
{
    Token token;
    std::istringstream input("\t   keyword\t1234 \"text\"   \n ");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::KEYWORD);
    EXPECT_EQ(token.value, "keyword");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::NUMBER);
    EXPECT_EQ(token.value, "1234");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::TEXT);
    EXPECT_EQ(token.value, "text");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::NEWLINE);
    EXPECT_EQ(token.value, "");
    token = Tokenizer::getNextToken(input);
    EXPECT_EQ(token.type, TokenType::EMPTY);
    EXPECT_EQ(token.value, "");
}
