#include "Canvas.h"

#include "operations/OperationFactory.h"

#include <FL/Fl.H>
#include <FL/fl_draw.H>

#include <cassert>

Canvas::Canvas(int width, int height, const char* title)
		: Fl_Double_Window(width, height, title)
{
    color(FL_WHITE);
    resizable(this);
    loadNodeImages();

    _expression = nullptr;
    _operation = OperationFactory::create(OperationType::NONE, nullptr);
}

void Canvas::draw()
{
    Fl_Double_Window::draw();
    drawExpression();
    drawMenuBar();
}

void Canvas::setExpression(Expression* expression)
{
    assert(expression != nullptr);
    _expression = expression;
    _operation = OperationFactory::create(OperationType::SELECT_NODE, _expression);
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
    const std::set<std::pair<Node*, Node*>> edges = _expression->getEdges();
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
    _operation->handleEvent(event);
    if (_operation->needChangeOperation()) {
        OperationType operationType = _operation->getNextOperationType();
        _operation = OperationFactory::create(operationType, _expression);
    }
    redraw();
    return 1;
}

void Canvas::loadNodeImages()
{
    _nodeImages = new Fl_PNG_Image("/tmp/nodes.png");
}

