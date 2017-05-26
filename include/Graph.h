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
    virtual void addNode(const Node& node);

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
    virtual void removeNode(int nodeId);

    /**
     * Add new edge from the source to the target node.
     */
    virtual void addEdge(const Edge& edge);

    /**
     * Get the edges of the expression.
     */
    const std::set<Edge>& getEdges() const;

    /**
     * Check that the graph has the given edge.
     */
    bool hasEdge(const Edge& edge) const;

    /**
     * Remove the edge from source node to target node.
     */
    virtual void removeEdge(const Edge& edge);

    /**
     * Update the last node identifier by the existing nodes.
     */
    void updateLastNodeId();

    /**
     * Check that the node has connected edge on the source side.
     */
    bool hasSource(int nodeId) const;

    /**
     * Check that the node has connected edge on the target side.
     */
    bool hasTarget(int nodeId) const;

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
