#include "Expression.h"

Expression::Expression()
{
}

void Expression::addNode(const Node& node)
{
    _nodes.push_back(std::unique_ptr<Node>(new Node(node)));
}

const std::vector<std::unique_ptr<Node>>& Expression::getNodes() const
{
    return _nodes;
}

void Expression::addEdge(Node* source, Node* target)
{
    std::pair<Node*, Node*> edge(source, target);
    _edges.push_back(edge);
}

const std::vector<std::pair<Node*, Node*>>& Expression::getEdges() const
{
    return _edges;
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

