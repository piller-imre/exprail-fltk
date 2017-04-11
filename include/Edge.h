#ifndef EDGE_H
#define EDGE_H

#include "Connector.h"

/**
 * Represents an edge between two nodes.
 */
class Edge
{
public:

    /**
     * Construct a new edge from two connectors.
     */
    Edge(const Connector& first, const Connector& second);

    /**
     * Get the first connector.
     */
    Connector getFirst() const;

    /**
     * Get the second connector.
     */
    Connector getSecond() const;

    /**
     * Compare two edges.
     */
    bool operator==(const Edge& other) const;

    /**
     * Check that the two edges are different.
     */
    bool operator!=(const Edge& other) const;

private:

    /**
     * First connector
     */
    Connector _first;

    /**
     * Second connector
     */
    Connector _second;
};

#endif /* EDGE_H */

