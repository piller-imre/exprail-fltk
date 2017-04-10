#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

#include <memory>
#include <map>
#include <set>
#include <utility>

/**
 * General purpose graph class
 */
class Graph
{
public:

    /**
     * Construct new graph.
     */
    Graph();

    /**
     * Add new node to the expression.
     */
    void addNode(const Node& node);

    /**
     * Get the node with the given identifier.
     */
    Node& getNode(int nodeId);

    /**
     * Get the nodes of the expression.
     */
    const std::map<int, Node>& getNodes() const;

    /**
     * Add new edge from the source to the target node.
     */
    void addEdge(Node* source, Node* target);

    /**
     * Get the edges of the expression.
     */
    const std::set<std::pair<Node*, Node*>>& getEdges() const;

protected:

    /**
     * Get new node identifier.
     */
    int getNewNodeId();

    /**
     * Nodes of the graph
     */
    std::map<int, Node> _nodes;

    /**
     * Edges of the graph
     */
    std::set<std::pair<Node*, Node*>> _edges;

    /**
     * The last node identifier
     */
    int _lastNodeId;
};

#endif /* GRAPH_H */

