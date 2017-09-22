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

private:

    /**
     * Check the start node.
     */
    static void checkStartNode(const Expression& expression, std::vector<std::string>& errorMessages);

    /**
     * Check the finish nodes.
     */
    static void checkFinishNodes(const Expression& expression, std::vector<std::string>& errorMessages);

    /**
     * Check the ground node.
     */
    static void checkGroundNode(const Expression& expression, std::vector<std::string>& errorMessages);
};

#endif /* VALIDATOR_H */
