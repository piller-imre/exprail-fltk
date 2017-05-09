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

