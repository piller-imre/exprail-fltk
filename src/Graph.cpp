#include "Graph.h"

Graph::Graph()
{
    _lastNodeId = 0;
}

void Graph::addNode(const Node& node)
{
    int nodeId = getNewNodeId();
    _nodes[nodeId] = node;
}

Node& Graph::getNode(int nodeId)
{
    // TODO: Check that the identifier is valid!
    return _nodes[nodeId];
}

const std::map<int, Node>& Graph::getNodes() const
{
    return _nodes;
}

void Graph::addEdge(Node* source, Node* target)
{
    std::pair<Node*, Node*> edge(source, target);
    _edges.insert(edge);
}

const std::set<std::pair<Node*, Node*>>& Graph::getEdges() const
{
    return _edges;
}

int Graph::getNewNodeId()
{
    ++_lastNodeId;
    return _lastNodeId;
}

