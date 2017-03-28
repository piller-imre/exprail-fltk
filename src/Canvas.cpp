#include "Canvas.h"

#include "operations/CreateNodeOperation.h"

#include <FL/Fl.H>
#include <FL/fl_draw.H>

#include <cassert>

// DEBUG
#include <iostream>
using namespace std;
//

Canvas::Canvas(int width, int height, const char* title)
		: Fl_Double_Window(width, height, title)
{
    color(FL_WHITE);
    resizable(this);
    loadNodeImages();

    // _expression = nullptr;
    _expression = new Expression();
    _operation = new Operation(_expression);
}

void Canvas::draw()
{
    Fl_Double_Window::draw();
    drawExpression();
    drawMenuBar();
}

void Canvas::setExpression(Expression* expression)
{
    _expression = expression;
}

void Canvas::drawMenuBar() const
{
    fl_rectf(0, 0, 384, 32, FL_GRAY);
    _nodeImages->draw(0, 0);
}

void Canvas::drawExpression() const
{
    if (_expression != nullptr) {
        // drawEdges();
        drawNodes();
    }
}

void Canvas::drawNodes() const
{
    assert(_expression != nullptr);
    const std::vector<Node>& nodes = _expression->getNodes();
    for (const Node& node : nodes) {
        drawNode(node);
    }
}

void Canvas::drawNode(const Node& node) const
{
    int x = node.getX() - 16;
    int y = node.getY() - 16;
    int cx = static_cast<int>(node.getType()) * 32;
    _nodeImages->draw(x, y, 32, 32, cx, 0);
}

int Canvas::handle(int event)
{
    MouseButton mouseButton;
    int mouseX, mouseY;

    mouseButton = MouseButton::LEFT;
    if (isMouseEvent(event)) {
        getMouseEventData(&mouseButton, &mouseX, &mouseY);
    }
    else {
        mouseX = 0;
        mouseY = 0;
    }

    switch (event) {
    case FL_PUSH:
        if (mouseX < 384 && mouseY < 32) {
            NodeType nodeType = static_cast<NodeType>(mouseX / 32);
            _operation = new CreateNodeOperation(_expression, nodeType);
        }
        else {
            _operation->pressMouse(mouseButton, mouseX, mouseY);
        }
        break;
    case FL_DRAG:
        _operation->dragMouse(mouseButton, mouseX, mouseY);
        break;
    case FL_RELEASE:
        _operation->releaseMouse(mouseButton, mouseX, mouseY);
        redraw();
        break;
    case FL_MOVE:
        _operation->moveMouse(mouseX, mouseY);
        break;
    }
    if (_operation->isCompleted()) {
        _operation = new Operation(_expression);
    }
    return 1;
}

bool Canvas::isMouseEvent(int event) const
{
    return event == FL_PUSH
        || event == FL_DRAG
        || event == FL_RELEASE
        || event == FL_MOVE;
}

void Canvas::getMouseEventData(MouseButton* mouseButton, int* mouseX, int* mouseY) const
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
    *mouseX = Fl::event_x();
    *mouseY = Fl::event_y();
}

void Canvas::loadNodeImages()
{
    _nodeImages = new Fl_PNG_Image("/tmp/nodes.png");
}

