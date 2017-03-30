#include "operations/OperationFactory.h"

#include "operations/CreateNodeOperation.h"
#include "operations/SelectNodeOperation.h"
#include "operations/SelectEdgeOperation.h"

Operation* OperationFactory::create(OperationType operationType, Expression* expression)
{
    switch (operationType) {
    case OperationType::NONE:
        break;
    case OperationType::CREATE_NODE:
        return new CreateNodeOperation(expression);
    case OperationType::SELECT_NODE:
        return new SelectNodeOperation(expression);
    case OperationType::SELECT_EDGE:
        return new SelectEdgeOperation(expression);
    }
    return nullptr;
}

