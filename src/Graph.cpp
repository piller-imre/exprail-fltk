#include "Graph.h"

Graph& Graph::operator=(const Graph& other)
{
    if (&other != this) {
        for (const std::unique_ptr<Node>& node : other._nodes) {
            _nodes.push_back(std::unique_ptr<Node>(new Node(*node)));
        }
        for (const std::pair<Node*, Node*>& edge : other._edges) {
            int sourceIndex = calcNodeIndex(edge.first);
            int targetIndex = calcNodeIndex(edge.second);
            Node* sourceNode = _nodes[sourceIndex].get();
            Node* targetNode = _nodes[targetIndex].get();
            std::pair<Node*, Node*> newEdge(sourceNode, targetNode);
        }
    }
    return *this;
}

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
    _edges.insert(edge);
}

const std::set<std::pair<Node*, Node*>>& Graph::getEdges() const
{
    return _edges;
}

int Graph::calcNodeIndex(const Node* node) const
{
    for (unsigned int i = 0; i < _nodes.size(); ++i) {
        if (_nodes[i].get() == node) {
            return i;
        }
    }
    // TODO: Throw an exception instead!
    return -1;
}

