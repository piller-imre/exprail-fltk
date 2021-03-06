#include "operations/SelectEdgeOperation.h"

SelectEdgeOperation::SelectEdgeOperation(Expression* expression)
    : Operation(expression)
{
}

void SelectEdgeOperation::pressMouse(MouseButton button, const Point& position)
{
    switch (button) {
    case MouseButton::LEFT:
        _expression->selectSourceNode(position);
        break;
    case MouseButton::RIGHT:
        _expression->selectTargetNode(position);
        break;
    case MouseButton::MIDDLE:
        _expression->toggleSelectedEdge();
        break;
    }
}

