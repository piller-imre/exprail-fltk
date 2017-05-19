#include "Expression.h"

Expression::Expression()
{
    _selectedNodeId = INVALID_ID;
    _sourceNodeId = INVALID_ID;
    _targetNodeId = INVALID_ID;
}

Expression::Expression(const std::map<int, Node> &nodes, const std::set<Edge> &edges)
    : Expression()
{
    _nodes = nodes;
    _edges = edges;
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

void Expression::selectSourceNode(const Point& position)
{
    _sourceNodeId = searchNode(position);
}

void Expression::selectTargetNode(const Point& position)
{
    _targetNodeId = searchNode(position);
}

int Expression::getSelectedNodeId() const
{
    return _selectedNodeId;
}

bool Expression::hasSelectedNode() const
{
    return _selectedNodeId != INVALID_ID;
}

const Node& Expression::getSelectedNode() const
{
    assert(hasSelectedNode());
    return _nodes.at(_selectedNodeId);
}

int Expression::getSourceNodeId() const
{
    return _sourceNodeId;
}

bool Expression::hasSourceNode() const
{
    return _sourceNodeId != INVALID_ID;
}

const Node& Expression::getSourceNode() const
{
    assert(hasSourceNode());
    return _nodes.at(_sourceNodeId);
}

int Expression::getTargetNodeId() const
{
    return _targetNodeId;
}

bool Expression::hasTargetNode() const
{
    return _targetNodeId != INVALID_ID;
}

const Node& Expression::getTargetNode() const
{
    assert(hasTargetNode());
    return _nodes.at(_targetNodeId);
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
        if (_sourceNodeId == _selectedNodeId) {
            _sourceNodeId = INVALID_ID;
        }
        if (_targetNodeId == _selectedNodeId) {
            _targetNodeId = INVALID_ID;
        }
        removeNode(_selectedNodeId);
        _selectedNodeId = INVALID_ID;
    }
}

void Expression::toggleSelectedEdge()
{
    if (_sourceNodeId != INVALID_ID && _targetNodeId != INVALID_ID) {
        Edge edge(_sourceNodeId, _targetNodeId);
        if (_edges.find(edge) == _edges.end()) {
            _edges.insert(edge);
        }
        else {
            _edges.erase(edge);
        }
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
    return INVALID_ID;
}

std::ostream& operator<<(std::ostream& outputStream, const Expression& expression)
{
    outputStream << "nodes" << std::endl;
    for (auto const& item : expression.getNodes()) {
        outputStream << item.first << " " << item.second << std::endl;
    }
    outputStream << "edges" << std::endl;
    for (const Edge& edge : expression.getEdges()) {
        outputStream << edge << std::endl;
    }
    return outputStream;
}
