#include "operations/SelectEdgeOperation.h"

SelectEdgeOperation::SelectEdgeOperation(Expression* expression)
    : Operation(expression)
{
}

void SelectEdgeOperation::pressMouse(MouseButton button, const Point& position)
{
    switch (button) {
    case MouseButton::LEFT:
        _expression->useFocusedAsSource(position);
        break;
    case MouseButton::RIGHT:
        _expression->useFocusedAsTarget(position);
        break;
    case MouseButton::MIDDLE:
        _expression->toggleSelectedEdge();
        break;
    }
}

