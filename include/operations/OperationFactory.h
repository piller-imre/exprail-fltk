#ifndef OPERATION_FACTORY
#define OPERATION_FACTORY

#include "Expression.h"
#include "Operation.h"

/**
 * Factory for creating various operations
 */
class OperationFactory
{
public:

    /**
     * Create a new operation instance for the given expression.
     */
    static Operation* create(OperationType operationType, Expression* expression);
};

#endif /* OPERATION_FACTORY */

