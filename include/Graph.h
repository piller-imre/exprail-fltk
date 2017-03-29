#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

#include <memory>
#include <set>
#include <vector>
#include <utility>

/**
 * General purpose graph class
 */
class Graph
{
public:

    /**
     * Add new node to the expression.
     */
    void addNode(const Node& node);

    /**
     * Get the nodes of the expression.
     */
    const std::vector<std::unique_ptr<Node>>& getNodes() const;

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
     * Nodes of the graph
     */
    std::vector<std::unique_ptr<Node>> _nodes;

    /**
     * Edges of the graph
     */
    std::set<std::pair<Node*, Node*>> _edges;
};

#endif /* GRAPH_H */

