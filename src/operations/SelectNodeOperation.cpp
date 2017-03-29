#include "operations/SelectNodeOperation.h"

SelectNodeOperation::SelectNodeOperation(Expression* expression)
    : Operation(expression)
{
    _selectedNode = nullptr;
}

void SelectNodeOperation::pressMouse(MouseButton button, int x, int y)
{
    _selectedNode = _expression->searchFocusedNode(x, y);
}

void SelectNodeOperation::dragMouse(MouseButton button, int x, int y)
{
    // TODO: Use shift instead of centering the node to the current mouse position!
    if (_selectedNode != nullptr) {
        _selectedNode->move(x, y);
    }
}

