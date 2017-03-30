#include "operations/CreateNodeOperation.h"

CreateNodeOperation::CreateNodeOperation(Expression* expression)
    : Operation(expression)
{
}

void CreateNodeOperation::releaseMouse(MouseButton button, int x, int y)
{
    _expression->createNewNode(x, y);
    _nextOperationType = OperationType::SELECT_NODE;
}

