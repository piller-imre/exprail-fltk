#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "Expression.h"

#include <map>
#include <string>
#include <vector>

/**
 * Represents a grammar definition
 */
class Grammar
{
public:

    /**
     * Construct an empty grammar without expressions.
     */
    Grammar();

    /**
     * Add new expression to the grammar.
     */
    void addExpression(const std::string& name, const Expression& expression);

    /**
     * Rename the expression from the old name to the new one.
     */
    void renameExpression(const std::string& oldName, const std::string& newName);

    /**
     * Remove the expression from the grammar.
     */
    void removeExpression(const std::string& name);

    /**
     * Get the expression by name.
     */
    Expression& getExpression(const std::string& name);

    /**
     * Get all expressions.
     */
    const std::map<std::string, Expression>& getExpressions() const;

    /**
     * Get the ordered list of the expressions.
     */
    const std::vector<std::string>& getExpressionOrder() const;

    /**
     * Move the selected expression down.
     */
    void moveExpressionDown(const std::string& name);

    /**
     * Move the selected expression up.
     */
    void moveExpressionUp(const std::string& name);

private:

    /**
     * Calculate the index of the expression in expression name order.
     */
    unsigned int calcExpressionIndex(const std::string& name) const;

    /**
     * Expressions of the grammar
     */
    std::map<std::string, Expression> _expressions;

    /**
     * The order of the expressions
     */
    std::vector<std::string> _expressionOrder;
};

/**
 * Write the content of the grammar to the output stream.
 */
std::ostream& operator<<(std::ostream& outputStream, Grammar& grammar);

#endif /* GRAMMAR_H */
