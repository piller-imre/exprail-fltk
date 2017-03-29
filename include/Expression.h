#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Graph.h"

/**
 * Represents the graph of an expression
 */
class Expression : public Graph
{
public:

    /**
     * Construct an empty expression graph.
     */
    Expression();

    /**
     * Search the focused node.
     */
    Node* searchFocusedNode(int x, int y);
};

#endif /* EXPRESSION_H */

