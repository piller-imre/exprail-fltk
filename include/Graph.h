#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

#include "Edge.h"

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
    const Node& getNode(int nodeId) const;

    /**
     * Get the nodes of the expression.
     */
    const std::map<int, Node>& getNodes() const;

    /**
     * Remove the given node.
     */
    void removeNode(int nodeId);

    /**
     * Add new edge from the source to the target node.
     */
    void addEdge(int sourceId, int targetId);

    /**
     * Get the edges of the expression.
     */
    const std::set<Edge>& getEdges() const;

    /**
     * Value for invalid node indices
     */
    static const int INVALID_ID;

protected:

    /**
     * Remove the edges which are connected to the node.
     */
    void removeConnectedEdges(int nodeId);

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
    std::set<Edge> _edges;

    /**
     * The last node identifier
     */
    int _lastNodeId;
};

#endif /* GRAPH_H */

