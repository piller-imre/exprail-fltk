#include "Expression.h"

Expression::Expression()
{
    _selectedNode = nullptr;
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
        _firstConnector = other._firstConnector;
        _secondConnector = other._secondConnector;
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
    Node node(_selectedNodeType, "", position - _origin);
    addNode(node);
    useFocusedAsSelected(position);
}

void Expression::useFocusedAsSelected(const Point& position)
{
    _selectedNode = searchNode(position);
}

void Expression::selectFirstConnector(const Point& position)
{
    _firstConnector = searchConnector(position);
}

void Expression::selectSecondConnector(const Point& position)
{
    _secondConnector = searchConnector(position);
}

const Node* Expression::getSelectedNode() const
{
    return _selectedNode;
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
    if (_selectedNode != nullptr) {
        _selectedNode->setPosition(position - _origin);
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
    if (_firstConnector.isValid() && _secondConnector.isValid()) {
        std::pair<Node*, Node*> edge(_firstConnector.getNode(), _secondConnector.getNode());
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

Node* Expression::searchNode(const Point& position)
{
    for (const std::unique_ptr<Node>& node : _nodes) {
        if (node->hasCollision(position - _origin)) {
            return node.get();
        }
    }
    return nullptr;
}

Connector Expression::searchConnector(const Point& position)
{
    Node* node = searchNode(position);
    if (node != nullptr) {
        if (position.getX() < node->getPosition().getX()) {
            return Connector(node, Side::LEFT);
        }
        else {
            return Connector(node, Side::RIGHT);
        }
    }
    return Connector();
}

