#include "operations/SelectEdgeOperation.h"

SelectEdgeOperation::SelectEdgeOperation(Expression* expression)
    : Operation(expression)
{
}

void SelectEdgeOperation::pressMouse(MouseButton button, int x, int y)
{
    switch (button) {
    case MouseButton::LEFT:
        _expression->useFocusedAsSource(x, y);
        break;
    case MouseButton::RIGHT:
        _expression->useFocusedAsTarget(x, y);
        break;
    case MouseButton::MIDDLE:
        _expression->toggleSelectedEdge();
        break;
    }
}

