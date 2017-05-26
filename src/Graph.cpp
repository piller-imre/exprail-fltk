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

void Graph::removeNode(int nodeId)
{
    assert(_nodes.find(nodeId) != _nodes.end());
    removeConnectedEdges(nodeId);
    _nodes.erase(nodeId);
    assert(_nodes.find(nodeId) == _nodes.end());
}

void Graph::addEdge(const Edge& edge)
{
    _edges.insert(edge);
}

const std::set<Edge>& Graph::getEdges() const
{
    return _edges;
}

bool Graph::hasEdge(const Edge& edge) const
{
    return _edges.find(edge) != _edges.end();
}

void Graph::removeEdge(const Edge& edge)
{
    _edges.erase(edge);
}

void Graph::updateLastNodeId()
{
    _lastNodeId = INVALID_ID;
    for (auto const& item : _nodes) {
        if (item.first > _lastNodeId) {
            _lastNodeId = item.first;
        }
    }
}

bool Graph::hasSource(int nodeId) const
{
    for (const Edge& edge : _edges) {
        if (edge.getTargetId() == nodeId) {
            return true;
        }
    }
    return false;
}

bool Graph::hasTarget(int nodeId) const
{
    for (const Edge& edge : _edges) {
        if (edge.getSourceId() == nodeId) {
            return true;
        }
    }
    return false;
}

int Graph::getNewNodeId()
{
    ++_lastNodeId;
    return _lastNodeId;
}

void Graph::removeConnectedEdges(int nodeId)
{
    for (auto it = _edges.begin(); it != _edges.end();) {
        if (it->getSourceId() == nodeId || it->getTargetId() == nodeId) {
            it = _edges.erase(it);
        }
        else {
            ++it;
        }
    }
}
