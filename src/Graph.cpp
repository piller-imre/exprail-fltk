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

const Node& Graph::getNode(int nodeId) const
{
    assert(_nodes.find(nodeId) != _nodes.end());
    return _nodes.at(nodeId);
}

const std::map<int, Node>& Graph::getNodes() const
{
    return _nodes;
}

void Graph::addEdge(int sourceId, int targetId)
{
    Edge edge(sourceId, targetId);
    _edges.insert(edge);
}

const std::set<Edge>& Graph::getEdges() const
{
    return _edges;
}

int Graph::getNewNodeId()
{
    ++_lastNodeId;
    return _lastNodeId;
}

