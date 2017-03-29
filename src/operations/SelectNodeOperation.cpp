#include "operations/SelectNodeOperation.h"

SelectNodeOperation::SelectNodeOperation(Expression* expression)
    : Operation(expression)
{
}

void SelectNodeOperation::pressMouse(MouseButton button, int x, int y)
{
    _expression->useFocusedAsSelected(x, y);
}

void SelectNodeOperation::dragMouse(MouseButton button, int x, int y)
{
    // TODO: Use shift instead of centering the node to the current mouse position!
    _expression->moveSelectedNode(x, y);
}

