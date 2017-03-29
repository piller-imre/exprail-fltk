#include "Expression.h"

Expression::Expression()
{
    _selectedNode = nullptr;
    _sourceNode = nullptr;
    _targetNode = nullptr;
}

void Expression::useFocusedAsSelected(int x, int y)
{
    _selectedNode = searchFocusedNode(x, y);
}

void Expression::useFocusedAsSource(int x, int y)
{
    _sourceNode = searchFocusedNode(x, y);
}

void Expression::useFocusedAsTarget(int x, int y)
{
    _targetNode = searchFocusedNode(x, y);
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

void Expression::moveSelectedNode(int x, int y)
{
    if (_selectedNode != nullptr) {
        _selectedNode->move(x, y);
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

Node* Expression::searchFocusedNode(int x, int y)
{
    for (const std::unique_ptr<Node>& node : _nodes) {
        if (node->hasCollision(x, y)) {
            return node.get();
        }
    }
    return nullptr;
}

