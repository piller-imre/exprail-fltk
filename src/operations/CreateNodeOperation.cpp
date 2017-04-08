#include "operations/CreateNodeOperation.h"

CreateNodeOperation::CreateNodeOperation(Expression* expression)
    : Operation(expression)
{
}

void CreateNodeOperation::releaseMouse(MouseButton button, const Point& position)
{
    _expression->createNewNode(position);
    _nextOperationType = OperationType::SELECT_NODE;
}

