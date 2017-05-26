#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Expression.h"

#include <vector>
#include <string>

/**
 * Class for expression validation
 */
class Validator
{
public:

    /**
     * Validate the expression and returns with error messages.
     */
    static std::vector<std::string> validate(const Expression& expression);

    /**
     * Count the nodes of the expression which have the given node type.
     */
    static unsigned int countNodesByType(const Expression& expression, NodeType nodeType);
};

#endif /* VALIDATOR_H */
