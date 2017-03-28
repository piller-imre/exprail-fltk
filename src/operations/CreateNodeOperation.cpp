#include "operations/CreateNodeOperation.h"

CreateNodeOperation::CreateNodeOperation(Expression* expression, NodeType nodeType)
    : Operation(expression)
{
    _nodeType = nodeType;
}

void CreateNodeOperation::releaseMouse(MouseButton button, int x, int y)
{
    Node node(_nodeType, "new", x, y);
    _expression->addNode(node);
}

