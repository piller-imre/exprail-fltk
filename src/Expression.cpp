#include "Expression.h"

Expression::Expression()
{
    _selectedNode = nullptr;
    _sourceNode = nullptr;
    _targetNode = nullptr;
    _offset = Point(0, 0);
}

Expression& Expression::operator=(const Expression& other)
{
    Graph::operator=(other);
    if (&other != this) {
        if (other._selectedNode != nullptr) {
            int selectedIndex = other.calcNodeIndex(other._selectedNode);
            _selectedNode = _nodes[selectedIndex].get();
        }
        else {
            _selectedNode = nullptr;
        }
        if (other._sourceNode != nullptr) {
            int sourceIndex = other.calcNodeIndex(other._sourceNode);
            _sourceNode = _nodes[sourceIndex].get();
        }
        else {
            _sourceNode = nullptr;
        }
        if (other._targetNode != nullptr) {
            int targetIndex = other.calcNodeIndex(other._targetNode);
            _targetNode = _nodes[targetIndex].get();
        }
        else {
            _targetNode = nullptr;
        }
    }
    return *this;
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
    Node node(_selectedNodeType, "", position - _offset);
    addNode(node);
    useFocusedAsSelected(position);
}

void Expression::useFocusedAsSelected(const Point& position)
{
    _selectedNode = searchFocusedNode(position);
}

void Expression::useFocusedAsSource(const Point& position)
{
    _sourceNode = searchFocusedNode(position);
}

void Expression::useFocusedAsTarget(const Point& position)
{
    _targetNode = searchFocusedNode(position);
}

const Node* Expression::getSelectedNode() const
{
    return _selectedNode;
}

const Node* Expression::getSourceNode() const
{
    return _sourceNode;
}

const Node* Expression::getTargetNode() const
{
    return _targetNode;
}

void Expression::moveSelectedNode(const Point& position)
{
    if (_selectedNode != nullptr) {
        _selectedNode->setPosition(position - _offset);
    }
}

void Expression::setSelectedNodeValue(const std::string& value)
{
    if (_selectedNode != nullptr) {
        _selectedNode->setValue(value);
    }
}

void Expression::removeSelectedNode()
{
    if (_selectedNode != nullptr) {
        int index = calcNodeIndex(_selectedNode);    
        _nodes.erase(_nodes.begin() + index);
        for (auto it = _edges.begin(); it != _edges.end();) {
            if (it->first == _selectedNode || it->second == _selectedNode) {
                it = _edges.erase(it);
            }
            else {
                ++it;
            }
        }
        _selectedNode = nullptr;
    }
}

void Expression::toggleSelectedEdge()
{
    if (_sourceNode != nullptr && _targetNode != nullptr) {
        std::pair<Node*, Node*> edge(_sourceNode, _targetNode);
        if (_edges.find(edge) == _edges.end()) {
            _edges.insert(edge);
        }
        else {
            _edges.erase(edge);
        }
    }
}

void Expression::shiftOffset(const Point& delta)
{
    _offset += delta;
}

Point Expression::getOffset() const
{
    return _offset;
}

Node* Expression::searchFocusedNode(const Point& position)
{
    for (const std::unique_ptr<Node>& node : _nodes) {
        if (node->hasCollision(position - _offset)) {
            return node.get();
        }
    }
    return nullptr;
}

