#include "Expression.h"

const int Expression::INVALID_ID = -1;

Expression::Expression()
{
    _selectedNodeId = 0;
}

void Expression::selectNodeType(NodeType nodeType)
{
    _selectedNodeType = nodeType;
}

NodeType Expression::getSelectedNodeType() const
{
    return _selectedNodeType;
}

void Expression::createNewNode(const Point& position)
{
    Node node(_selectedNodeType, "", position - _origin);
    addNode(node);
    useFocusedAsSelected(position);
}

void Expression::useFocusedAsSelected(const Point& position)
{
    _selectedNodeId = searchNode(position);
}

void Expression::selectFirstConnector(const Point& position)
{
    _firstConnector = searchConnector(position);
}

void Expression::selectSecondConnector(const Point& position)
{
    _secondConnector = searchConnector(position);
}

int Expression::getSelectedNodeId() const
{
    return _selectedNodeId;
}

const Connector Expression::getFirstConnector() const
{
    return _firstConnector;
}

const Connector Expression::getSecondConnector() const
{
    return _secondConnector;
}

void Expression::moveSelectedNode(const Point& position)
{
    if (_selectedNodeId != INVALID_ID) {
        _nodes[_selectedNodeId].setPosition(position - _origin);
    }
}

void Expression::setSelectedNodeValue(const std::string& value)
{
    if (_selectedNodeId != INVALID_ID) {
        _nodes[_selectedNodeId].setValue(value);
    }
}

void Expression::removeSelectedNode()
{
    if (_selectedNodeId != INVALID_ID) {
        // TODO: Remove the connected edges!
        _nodes.erase(_selectedNodeId);
        _selectedNodeId = INVALID_ID;
    }
}

void Expression::toggleSelectedEdge()
{
    if (_firstConnector.isValid() && _secondConnector.isValid()) {
        // TODO: Toggle selected edge on valid selection!
    }
}

void Expression::shiftOrigin(const Point& delta)
{
    _origin += delta;
}

Point Expression::getOrigin() const
{
    return _origin;
}

int Expression::searchNode(const Point& position)
{
    for (const auto& item : _nodes) {
        if (item.second.hasCollision(position - _origin)) {
            return item.first;
        }
    }
    // TODO: Raise an exception when there is no result!
    return 0;
}

Connector Expression::searchConnector(const Point& position)
{
    for (const auto& item : _nodes) {
        int nodeId = item.first;
        const Node& node = item.second;
        if (node.hasCollision(position - _origin)) {
            if (position.getX() < node.getPosition().getX()) {
                return Connector(nodeId, Side::LEFT);
            }
            else {
                return Connector(nodeId, Side::RIGHT);
            }
        }
    }
    return Connector();
}

