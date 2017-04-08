#include "Canvas.h"

#include "operations/OperationFactory.h"

#include <cassert>

Canvas::Canvas(int width, int height, const char* title)
		: Fl_Double_Window(width, height, title)
{
    color(FL_WHITE);
    resizable(this);

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
    drawer.setColor(200, 200, 200);
    drawer.fillRectangle(Point(0, 0), 384, 32);
    drawer.drawIconImage(Point(0, 0));
}

void Canvas::drawExpression()
{
    if (_expression != nullptr) {
        drawer.setOrigin(_expression->getOrigin());
        drawIndicators();
        drawEdges();
        drawNodes();
        drawer.setOrigin(Point(0, 0));
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
        drawer.setColor(240, 200, 0);
        drawer.drawCircle(selectedNode->getPosition(), 40);
    }
}

void Canvas::indicateSourceNode() const
{
    const Node* sourceNode = _expression->getSourceNode();
    if (sourceNode != nullptr) {
        drawer.setColor(255, 0, 0);
        drawer.drawCircle(sourceNode->getPosition(), 40);
    }
}

void Canvas::indicateTargetNode() const
{
    const Node* targetNode = _expression->getTargetNode();
    if (targetNode != nullptr) {
        drawer.setColor(0, 255, 0);
        drawer.drawCircle(targetNode->getPosition(), 40);
    }
}

void Canvas::drawEdges() const
{
    assert(_expression != nullptr);
    const std::set<std::pair<Node*, Node*>> edges = _expression->getEdges();
    drawer.setColor(255, 0, 0);
    for (const std::pair<Node*, Node*>& edge : edges) {
        const Node* source = edge.first;
        const Node* target= edge.second;
        assert(source != nullptr);
        assert(target != nullptr);
        drawer.drawLine(source->getPosition(), target->getPosition());
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
    drawer.drawIcon(static_cast<int>(node.getType()), node.getPosition() - Point(16, 16));
    drawer.setColor(50, 50, 200);
    drawer.drawText(node.getValue(), node.getPosition() + Point(-24, 28));
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

