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
    MouseButton mouseButton;
    int mouseX, mouseY;
    int key;

    switch (event) {
    case FL_PUSH:
        getMouseEventData(&mouseButton, &mouseX, &mouseY);
        pressMouse(mouseButton, mouseX, mouseY);
        break;
    case FL_RELEASE:
        getMouseEventData(&mouseButton, &mouseX, &mouseY);
        releaseMouse(mouseButton, mouseX, mouseY);
        break;
    case FL_MOVE:
        getMouseEventData(&mouseButton, &mouseX, &mouseY);
        moveMouse(mouseX, mouseY);
        break;
    case FL_DRAG:
        getMouseEventData(&mouseButton, &mouseX, &mouseY);
        dragMouse(mouseButton, mouseX, mouseY);
        break;
    case FL_KEYDOWN:
        getKeyEventData(&key);
        pressKey(key);
        break;
    case FL_KEYUP:
        getKeyEventData(&key);
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

void Operation::pressMouse(MouseButton button, int x, int y)
{
}

void Operation::releaseMouse(MouseButton button, int x, int y)
{
}

void Operation::moveMouse(int x, int y)
{
}

void Operation::dragMouse(MouseButton button, int x, int y)
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

void Operation::getMouseEventData(MouseButton* mouseButton, int* mouseX, int* mouseY) const
{
    int button = Fl::event_button();
    if (button == FL_LEFT_MOUSE) {
        *mouseButton = MouseButton::LEFT;
    }
    else if (button == FL_RIGHT_MOUSE) {
        *mouseButton = MouseButton::RIGHT;
    }
    else if (button == FL_MIDDLE_MOUSE) {
        *mouseButton = MouseButton::MIDDLE;
    }
    else {
        *mouseButton = MouseButton::LEFT;
    }
    *mouseX = Fl::event_x();
    *mouseY = Fl::event_y();
}

void Operation::getKeyEventData(int* key) const
{
    *key = Fl::event_key();
}

void Operation::removeSelectedNode()
{
    const Node* selectedNode;
    int response;

    selectedNode = _expression->getSelectedNode();
    if (selectedNode != nullptr) {
        response = fl_choice("Do you want to remove the selected node?", "Remove", "Cancel", 0);
        if (response == 0) {
            _expression->removeSelectedNode();
        }
    }
}

void Operation::renameSelectedNode()
{
    const Node* selectedNode;
    const char* value;

    selectedNode = _expression->getSelectedNode();
    if (selectedNode != nullptr) {
        value = fl_input("The new value of the node", selectedNode->getValue().c_str());
        if (value != nullptr) {
            _expression->setSelectedNodeValue(value);
        }
    }
}

