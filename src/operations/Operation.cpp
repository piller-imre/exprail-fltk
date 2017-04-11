#include "operations/Operation.h"

#include <FL/Fl.H>
#include <FL/Fl_File_Chooser.H>

Operation::Operation(Expression* expression)
{
    _expression = expression;
    _nextOperationType = OperationType::NONE;
}

void Operation::handleEvent(int event)
{
    MouseButton button;
    Point position;
    int key;

    switch (event) {
    case FL_PUSH:
        getMouseEventData(button, position);
        pressMouse(button, position);
        break;
    case FL_RELEASE:
        getMouseEventData(button, position);
        releaseMouse(button, position);
        break;
    case FL_MOVE:
        getMouseEventData(button, position);
        moveMouse(position);
        break;
    case FL_DRAG:
        getMouseEventData(button, position);
        dragMouse(button, position);
        break;
    case FL_KEYDOWN:
        getKeyEventData(key);
        pressKey(key);
        break;
    case FL_KEYUP:
        getKeyEventData(key);
        releaseKey(key);
        break;
    }
}

bool Operation::needChangeOperation() const
{
    if (_nextOperationType != OperationType::NONE) {
        return true;
    }
    else {
        return false;
    }
}

OperationType Operation::getNextOperationType() const
{
    return _nextOperationType;
}

void Operation::pressMouse(MouseButton button, const Point& position)
{
}

void Operation::releaseMouse(MouseButton button, const Point& position)
{
}

void Operation::moveMouse(const Point& position)
{
}

void Operation::dragMouse(MouseButton button, const Point& position)
{
}

void Operation::pressKey(int key)
{
    switch (key) {
    case 'w':
        removeSelectedNode();
        break;
    case 'e':
        renameSelectedNode();
        break;
    case 'r':
        // TODO: Change the type of the selected node!
        break;
    case 's':
        _nextOperationType = OperationType::SELECT_NODE;
        break;
    case 'd':
        // TODO: Move the offset of the expression!
        break;
    case 'f':
        _nextOperationType = OperationType::SELECT_EDGE;
        break;
    }
}

void Operation::releaseKey(int key)
{
}

void Operation::getMouseEventData(MouseButton& button, Point& position) const
{
    int index = Fl::event_button();
    if (index == FL_LEFT_MOUSE) {
        button = MouseButton::LEFT;
    }
    else if (index == FL_RIGHT_MOUSE) {
        button = MouseButton::RIGHT;
    }
    else if (index == FL_MIDDLE_MOUSE) {
        button = MouseButton::MIDDLE;
    }
    else {
        button = MouseButton::LEFT;
    }
    position.setX(Fl::event_x());
    position.setY(Fl::event_y());
}

void Operation::getKeyEventData(int& key) const
{
    key = Fl::event_key();
}

void Operation::removeSelectedNode()
{
    // TODO: Try to get selected node and after remove it instead of using node id!
    int selectedNodeId = _expression->getSelectedNodeId();
    if (selectedNodeId != Expression::INVALID_ID) {
        int response = fl_choice("Do you want to remove the selected node?", "Remove", "Cancel", 0);
        if (response == 0) {
            _expression->removeSelectedNode();
        }
    }
}

void Operation::renameSelectedNode()
{
    // TODO: Try to get selected node and after remove it instead of using node id!
    int selectedNodeId = _expression->getSelectedNodeId();
    if (selectedNodeId != Expression::INVALID_ID) {
        const Node& node = _expression->getNode(selectedNodeId);
        const char* value = fl_input("The new value of the node", node.getValue().c_str());
        if (value != nullptr) {
            _expression->setSelectedNodeValue(value);
        }
    }
}

