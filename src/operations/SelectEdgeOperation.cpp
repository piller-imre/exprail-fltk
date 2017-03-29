#include "operations/SelectEdgeOperation.h"

SelectEdgeOperation::SelectEdgeOperation(Expression* expression)
    : Operation(expression)
{
    _sourceNode = nullptr;
    _targetNode = nullptr;
}

void SelectEdgeOperation::pressMouse(MouseButton button, int x, int y)
{
    Node* node = _expression->searchFocusedNode(x, y);
    switch (button) {
    case MouseButton::LEFT:
        if (node != nullptr) {
            _sourceNode = node;
        }
        break;
    case MouseButton::RIGHT:
        if (node != nullptr) {
            _targetNode = node;
        }
        break;
    case MouseButton::MIDDLE:
        if (_sourceNode != nullptr && _targetNode != nullptr) {
            // Create edge ...
        }
        break;
    }
}

