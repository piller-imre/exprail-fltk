#include "operations/SelectNodeOperation.h"

SelectNodeOperation::SelectNodeOperation(Expression* expression)
    : Operation(expression)
{
    _prevX = 0;
    _prevY = 0;
}

void SelectNodeOperation::pressMouse(MouseButton button, int x, int y)
{
    if (button == MouseButton::LEFT) {
        if (x < 384 && y < 32) {
            NodeType nodeType = static_cast<NodeType>(x / 32);
            _expression->selectNodeType(nodeType);
            _nextOperationType = OperationType::CREATE_NODE;
        }
        else {
            _expression->useFocusedAsSelected(x, y);
        }
    }
    else {
        _prevX = x;
        _prevY = y;
    }
}

void SelectNodeOperation::dragMouse(MouseButton button, int x, int y)
{
    // TODO: Use shift instead of centering the node to the current mouse position!
    if (button == MouseButton::LEFT) {
        _expression->moveSelectedNode(x, y);
    }
    else {
        int dx = x - _prevX;
        int dy = y - _prevY;
        _expression->shiftOffset(dx, dy);
        _prevX = x;
        _prevY = y;
    }
}

