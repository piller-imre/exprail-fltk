#include "Graph.h"

void Graph::addNode(const Node& node)
{
    _nodes.push_back(std::unique_ptr<Node>(new Node(node)));
}

const std::vector<std::unique_ptr<Node>>& Graph::getNodes() const
{
    return _nodes;
}

void Graph::addEdge(Node* source, Node* target)
{
    std::pair<Node*, Node*> edge(source, target);
    _edges.push_back(edge);
}

const std::vector<std::pair<Node*, Node*>>& Graph::getEdges() const
{
    return _edges;
}

