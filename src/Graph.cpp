#include "Graph.h"

#include <cassert>

const int Graph::INVALID_ID = -1;

Graph::Graph()
{
    _lastNodeId = 0;
}

void Graph::addNode(const Node& node)
{
    int nodeId = getNewNodeId();
    assert(_nodes.find(nodeId) == _nodes.end());
    _nodes[nodeId] = node;
}

Node& Graph::getNode(int nodeId)
{
    assert(_nodes.find(nodeId) != _nodes.end());
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

