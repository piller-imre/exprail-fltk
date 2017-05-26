#include "Expression.h"

#include "Validator.h"

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

void Expression::addNode(const Node& node)
{
    Graph::addNode(node);
    updateIndicators();
}

void Expression::removeNode(int nodeId)
{
    Graph::removeNode(nodeId);
    updateIndicators();
}

void Expression::addEdge(const Edge& edge)
{
    Graph::addEdge(edge);
    updateIndicators();
}

void Expression::removeEdge(const Edge& edge)
{
    Graph::removeEdge(edge);
    updateIndicators();
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
        // TODO: Use pointers in the indicator for avoiding recalculations of all indicators!
        updateIndicators();
    }
}

void Expression::setSelectedNodeValue(const std::string& value)
{
    if (_selectedNodeId != INVALID_ID) {
        _nodes[_selectedNodeId].setValue(value);
        updateIndicators();
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
        if (hasEdge(edge) == false) {
            addEdge(edge);
        }
        else {
            removeEdge(edge);
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

const std::vector<Indicator>& Expression::getIndicators() const
{
    return _indicators;
}

const std::vector<std::string>& Expression::getErrorMessages() const
{
    return _errorMessages;
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

void Expression::updateIndicators()
{
    _indicators.clear();
    for (const auto& item : _nodes) {
        int nodeId = item.first;
        const Node& node = item.second;
        Indicator indicator(node);
        switch (node.getType()) {
        case NodeType::START:
        case NodeType::GROUND:
            if (hasSource(nodeId) == true) {
                indicator.enableSourceError();
            }
            break;
        default:
            if (hasSource(nodeId) == false) {
                indicator.enableSourceError();
            }
            break;
        }
        switch (node.getType()) {
        case NodeType::FINISH:
        case NodeType::ERROR:
            if (hasTarget(nodeId) == true) {
                indicator.enableTargetError();
            }
            break;
        default:
            if (hasTarget(nodeId) == false) {
                indicator.enableTargetError();
            }
            break;
        }
        if (node.hasValueError()) {
            indicator.enableValueError();
        }
        if (indicator.hasSourceError() || indicator.hasTargetError() || indicator.hasValueError()) {
            _indicators.push_back(indicator);
        }
    }
    updateErrorMessages();
}

void Expression::updateErrorMessages()
{
    _errorMessages = Validator::validate(*this);
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
