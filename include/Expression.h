#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Node.h"

#include <vector>
#include <utility>

/**
 * Represents the graph of an expression
 */
class Expression
{
public:

    /**
     * Construct an empty expression graph.
     */
    Expression();

    /**
     * Add new node to the expression.
     */
    void addNode(const Node& node);

    /**
     * Add new edge from node a to node b.
     */
    void addEdge(Node* a, Node* b);

private:

    /**
     * Nodes of the graph
     */
    std::vector<Node> _nodes;

    /**
     * Edges
     */
    std::vector<std::pair<Node*, Node*>> _edges;
};

#endif /* EXPRESSION_H */

