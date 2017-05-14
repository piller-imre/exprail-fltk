#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "Expression.h"

#include <map>
#include <string>

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

private:

    /**
     * Expressions of the grammar
     */
    std::map<std::string, Expression> _expressions;
};

#endif /* GRAMMAR_H */
