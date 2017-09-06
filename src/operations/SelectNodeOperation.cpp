#include "operations/SelectNodeOperation.h"

SelectNodeOperation::SelectNodeOperation(Expression* expression)
    : Operation(expression)
{
    _prevPosition = Point(0, 0);
}

void SelectNodeOperation::pressMouse(MouseButton button, const Point& position)
{
    if (button == MouseButton::LEFT) {
        if (position.getX() < 448 && position.getY() < 32) {
            NodeType nodeType = static_cast<NodeType>(position.getX() / 32);
            _expression->selectNodeType(nodeType);
            _nextOperationType = OperationType::CREATE_NODE;
        }
        else {
            _expression->useFocusedAsSelected(position);
        }
    }
    else {
        _prevPosition = position;
    }
}

void SelectNodeOperation::dragMouse(MouseButton button, const Point& position)
{
    // TODO: Use shift instead of centering the node to the current mouse position!
    if (button == MouseButton::LEFT) {
        _expression->moveSelectedNode(position);
    }
    else {
        Point delta = position - _prevPosition;
        _expression->shiftOrigin(delta);
        _prevPosition = position;
    }
}

