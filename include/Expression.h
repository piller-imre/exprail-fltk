#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Node.h"

#include <memory>
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
    const std::vector<std::pair<Node*, Node*>>& getEdges() const;

    /**
     * Search the focused node.
     */
    Node* searchFocusedNode(int x, int y);

private:

    /**
     * Nodes of the graph
     */
    std::vector<std::unique_ptr<Node>> _nodes;

    /**
     * Edges
     */
    std::vector<std::pair<Node*, Node*>> _edges;
};

#endif /* EXPRESSION_H */

