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
    indicateSelectedNode();
    indicateSourceNode();
    indicateTargetNode();
}

void Canvas::indicateSelectedNode() const
{
    const Node* selectedNode = _expression->getSelectedNode();
    if (selectedNode != nullptr) {
        int nodeX = selectedNode->getX() + _expression->getOffsetX();
        int nodeY = selectedNode->getY() + _expression->getOffsetY();
        fl_color(240, 200, 0);
        fl_arc(nodeX - 20, nodeY - 20, 40, 40, 0, 360);
    }
}

void Canvas::indicateSourceNode() const
{
    const Node* sourceNode = _expression->getSourceNode();
    if (sourceNode != nullptr) {
        int nodeX = sourceNode->getX() + _expression->getOffsetX();
        int nodeY = sourceNode->getY() + _expression->getOffsetY();
        fl_color(255, 0, 0);
        fl_arc(nodeX - 20, nodeY - 20, 40, 40, 0, 360);
    }
}

void Canvas::indicateTargetNode() const
{
    const Node* targetNode = _expression->getTargetNode();
    if (targetNode != nullptr) {
        int nodeX = targetNode->getX() + _expression->getOffsetX();
        int nodeY = targetNode->getY() + _expression->getOffsetY();
        fl_color(0, 255, 0);
        fl_arc(nodeX - 20, nodeY - 20, 40, 40, 0, 360);
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
        int sourceX = source->getX() + _expression->getOffsetX();
        int sourceY = source->getY() + _expression->getOffsetY();
        int targetX = target->getX() + _expression->getOffsetX();
        int targetY = target->getY() + _expression->getOffsetY();
        fl_line(sourceX, sourceY, targetX, targetY);
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
    int nodeX = node.getX() + _expression->getOffsetX();
    int nodeY = node.getY() + _expression->getOffsetY();
    int cx = static_cast<int>(node.getType()) * 32;
    _nodeImages->draw(nodeX - 16, nodeY - 16, 32, 32, cx, 0);
    fl_color(50, 50, 200);
    fl_draw(node.getValue().c_str(), nodeX - 24, nodeY + 28);
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

