#include "Canvas.h"

#include "operations/CreateNodeOperation.h"
#include "operations/SelectNodeOperation.h"
#include "operations/SelectEdgeOperation.h"

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
    _operation = new SelectNodeOperation(_expression);
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
        drawIndicators();
        drawEdges();
        drawNodes();
    }
}

void Canvas::drawIndicators() const
{
    const Node* selectedNode = _expression->getSelectedNode();
    if (selectedNode != nullptr) {
        fl_color(240, 200, 0);
        fl_arc(selectedNode->getX() - 20, selectedNode->getY() - 20, 40, 40, 0, 360);
    }
    const Node* sourceNode = _expression->getSourceNode();
    if (sourceNode != nullptr) {
        fl_color(255, 0, 0);
        fl_arc(sourceNode->getX() - 20, sourceNode->getY() - 20, 40, 40, 0, 360);
    }
    const Node* targetNode = _expression->getTargetNode();
    if (targetNode != nullptr) {
        fl_color(0, 255, 0);
        fl_arc(targetNode->getX() - 20, targetNode->getY() - 20, 40, 40, 0, 360);
    }
}

void Canvas::drawEdges() const
{
    assert(_expression != nullptr);
    const std::vector<std::pair<Node*, Node*>> edges = _expression->getEdges();
    fl_color(255, 0, 0);
    for (const std::pair<Node*, Node*>& edge : edges) {
        const Node* source = edge.first;
        const Node* target= edge.second;
        assert(source != nullptr);
        assert(target != nullptr);
        fl_line(source->getX(), source->getY(), target->getX(), target->getY());
    }
}

void Canvas::drawNodes() const
{
    assert(_expression != nullptr);
    const std::vector<std::unique_ptr<Node>>& nodes = _expression->getNodes();
    for (const std::unique_ptr<Node>& node : nodes) {
        drawNode(*node);
    }
}

void Canvas::drawNode(const Node& node) const
{
    int x = node.getX() - 16;
    int y = node.getY() - 16;
    int cx = static_cast<int>(node.getType()) * 32;
    _nodeImages->draw(x, y, 32, 32, cx, 0);
    fl_color(50, 50, 200);
    fl_draw(node.getValue().c_str(), node.getX() - 24, node.getY() + 28);
}

int Canvas::handle(int event)
{
    // TODO: Make proper deallocation when changing operation for avoiding memory leak!
    MouseButton mouseButton;
    int mouseX, mouseY;
    int key;

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
        redraw();
        break;
    case FL_DRAG:
        _operation->dragMouse(mouseButton, mouseX, mouseY);
        redraw();
        break;
    case FL_RELEASE:
        _operation->releaseMouse(mouseButton, mouseX, mouseY);
        redraw();
        break;
    case FL_MOVE:
        _operation->moveMouse(mouseX, mouseY);
        break;
    case FL_KEYDOWN:
        key = Fl::event_key();
        switch (key) {
        case 'w':
            // TODO: Remove the selected node!
            break;
        case 'e':
            // TODO: Toggle the selected edge!
            break;
        case 'r':
            break;
        case 's':
            _operation = new SelectNodeOperation(_expression);
            break;
        case 'd':
            // TODO: Move the offset of the expression!
            break;
        case 'f':
            _operation = new SelectEdgeOperation(_expression);
            break;
        }
        break;
    case FL_KEYUP:
        break;
    default:
        // cout << "event: " << event << endl;
        break;
    }
    if (_operation->isCompleted()) {
        _operation = new SelectNodeOperation(_expression);
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

