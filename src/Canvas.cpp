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
    indicateFirstConnector();
    indicateSecondConnector();
}

void Canvas::indicateSelectedNode() const
{
    int nodeId = _expression->getSelectedNodeId();
    if (nodeId != Expression::INVALID_ID) {
        const Node& node = _expression->getNode(nodeId);
        drawer.setColor(240, 200, 0);
        drawer.drawCircle(node.getPosition(), 30);
    }
}

void Canvas::indicateFirstConnector() const
{
    const Connector connector = _expression->getFirstConnector();
    drawer.setColor(255, 0, 0);
    drawConnector(connector);
}

void Canvas::indicateSecondConnector() const
{
    const Connector connector = _expression->getSecondConnector();
    drawer.setColor(0, 255, 0);
    drawConnector(connector);
}

void Canvas::drawConnector(const Connector& connector) const
{
    if (connector.isValid()) {
        const Node& node = _expression->getNode(connector.getNodeId());
        Point position = node.getPosition();
        if (connector.getSide() == Side::LEFT) {
            position -= Point(16, 0);
        }
        else {
            position += Point(16, 0);
        }
        drawer.drawCircle(position, 10);
    }
}

void Canvas::drawEdges() const
{
    // TODO: Use drawEdge method for drawing!
    assert(_expression != nullptr);
    const std::set<std::pair<Node*, Node*>> edges = _expression->getEdges();
    drawer.setColor(255, 0, 0);
    for (const std::pair<Node*, Node*>& edge : edges) {
        const Node* source = edge.first;
        const Node* target = edge.second;
        assert(source != nullptr);
        assert(target != nullptr);
        drawer.drawLine(source->getPosition(), target->getPosition());
    }
}

void Canvas::drawNodes() const
{
    assert(_expression != nullptr);
    const std::map<int, Node>& nodes = _expression->getNodes();
    for (const auto& item : nodes) {
        drawNode(item.second);
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

