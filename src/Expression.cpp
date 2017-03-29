#include "Expression.h"

Expression::Expression()
{
}

void Expression::addNode(const Node& node)
{
    _nodes.push_back(node);
}

const std::vector<Node>& Expression::getNodes() const
{
    return _nodes;
}

void Expression::addEdge(Node* a, Node* b)
{
    std::pair<Node*, Node*> edge(a, b);
    _edges.push_back(edge);
}

Node* Expression::searchFocusedNode(int x, int y)
{
    for (Node& node : _nodes) {
        if (node.hasCollision(x, y)) {
            return &node;
        }
    }
    return nullptr;
}

