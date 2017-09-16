#include "Canvas.h"

#include "Point.h"
#include "operations/OperationFactory.h"

#include <FL/Fl.H>

#include <cassert>

Canvas::Canvas(int width, int height, const char* title)
		: Fl_Double_Window(width, height, title)
{
    color(FL_WHITE);
    resizable(this);

    _expression = nullptr;
    _operation = OperationFactory::create(OperationType::NONE, nullptr);

    _isNodeIdDisplayed = false;
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
    _drawer.setColor(_theme.toolbarColor());
    _drawer.fillRectangle(Point(0, 0), 17 * 32, 32);
    for (int i = 0; i < 17; ++i) {
        Node node(static_cast<NodeType>(i), "", Point(0, 0));
        Fl_PNG_Image* image = _iconPack.getNodeImage(node);
        _drawer.drawIcon(image, Point(i * 32, 0));
    }
}

void Canvas::drawExpression()
{
    if (_expression != nullptr) {
        _drawer.setOrigin(_expression->getOrigin());
        drawIndicators();
        drawEdges();
        drawNodes();
        drawErrorMessages();
        _drawer.setOrigin(Point(0, 0));
    }
}

void Canvas::drawIndicators() const
{
    if (_expression->hasSelectedNode()) {
        indicateSelectedNode();
    }
    if (_expression->hasSourceNode()) {
        indicateSourceNode();
    }
    if (_expression->hasTargetNode()) {
        indicateTargetNode();
    }
    for (const Indicator& indicator : _expression->getIndicators()) {
        if (indicator.hasSourceError()) {
            _drawer.drawIndicator(_iconPack.getIndicatorImage(IndicatorType::SOURCE_ERROR), indicator.getNode().getPosition());
        }
        if (indicator.hasTargetError()) {
            _drawer.drawIndicator(_iconPack.getIndicatorImage(IndicatorType::TARGET_ERROR), indicator.getNode().getPosition());
        }
        if (indicator.hasValueError()) {
            _drawer.drawIndicator(_iconPack.getIndicatorImage(IndicatorType::VALUE_ERROR), indicator.getNode().getPosition());
        }
    }
}

void Canvas::drawErrorMessages() const
{
    int x = 20;
    int y = 60;
    _drawer.setColor(_theme.errorMessageColor());
    for (const std::string& errorMessage : _expression->getErrorMessages()) {
        _drawer.drawMessage(errorMessage, Point(x, y));
        y += 24;
    }
}

void Canvas::indicateSelectedNode() const
{
    const Node& node = _expression->getSelectedNode();
    _drawer.drawIndicator(_iconPack.getIndicatorImage(IndicatorType::SELECTION), node.getPosition());

}

void Canvas::indicateSourceNode() const
{
    const Node& node = _expression->getSourceNode();
    _drawer.drawIndicator(_iconPack.getIndicatorImage(IndicatorType::SOURCE), node.getPosition());
}

void Canvas::indicateTargetNode() const
{
    const Node& node = _expression->getTargetNode();
    _drawer.drawIndicator(_iconPack.getIndicatorImage(IndicatorType::TARGET), node.getPosition());
}

void Canvas::drawEdges() const
{
    assert(_expression != nullptr);
    _drawer.setColor(_theme.lineColor());
    for (const Edge& edge : _expression->getEdges()) {
        drawEdge(edge);
    }
}

void Canvas::drawEdge(const Edge& edge) const
{
    Node sourceNode = _expression->getNode(edge.getSourceId());
    Node targetNode = _expression->getNode(edge.getTargetId());
    Point sourcePoint = sourceNode.getPosition() + Point(16, 0);
    Point targetPoint = targetNode.getPosition() - Point(16, 0);
    _drawer.drawEdge(sourcePoint, targetPoint, _theme.curviness());
}

void Canvas::drawNodes() const
{
    assert(_expression != nullptr);
    const std::map<int, Node>& nodes = _expression->getNodes();
    for (const auto& item : nodes) {
        drawNode(item.second);
        if (_isNodeIdDisplayed) {
            _drawer.setColor(80, 200, 100);
            _drawer.drawText(std::to_string(item.first), item.second.getPosition() + Point(-5, -25));
        }
    }
}

void Canvas::drawNode(const Node& node) const
{
    Fl_PNG_Image* image = _iconPack.getNodeImage(node);
    _drawer.drawIcon(image, node.getPosition() - Point(16, 16));
    _drawer.setColor(_theme.nodeLabelColor());
    if (_iconPack.isCustomNode(node) == false) {
        _drawer.drawText(node.getValue(), node.getPosition() + Point(-24, 28));
    }
}

int Canvas::handle(int event)
{
    if (event == FL_KEYDOWN) {
        int key = Fl::event_key();
        if (key == 'h') {
            _isNodeIdDisplayed = !_isNodeIdDisplayed;
        }
    }
    if (_expression != nullptr) {
        // TODO: Make proper deallocation when changing operation for avoiding memory leak!
        _operation->handleEvent(event);
        if (_operation->needChangeOperation()) {
            OperationType operationType = _operation->getNextOperationType();
            _operation = OperationFactory::create(operationType, _expression);
        }
        redraw();
    }
    return 1;
}
