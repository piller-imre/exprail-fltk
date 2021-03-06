#ifndef EDGE_H
#define EDGE_H

#include <ostream>

/**
 * Represents a directed edge between two nodes.
 */
class Edge
{
public:

    /**
     * Construct a new edge from node identifiers.
     */
    Edge(int sourceId, int targetId);

    /**
     * Get the identifier of the source node.
     */
    int getSourceId() const;

    /**
     * Get the identifier of the target node.
     */
    int getTargetId() const;

    /**
     * Compare two edges.
     */
    bool operator==(const Edge& other) const;

    /**
     * Check that the two edges are different.
     */
    bool operator!=(const Edge& other) const;

    /**
     * Comparison operator for lexical ordering.
     */
    bool operator<(const Edge& other) const;

private:

    /**
     * The identifier of the source node
     */
    int _sourceId;

    /**
     * The identifier of the target node
     */
    int _targetId;
};

/**
 * Write the content of the edge to the output stream.
 */
std::ostream& operator<<(std::ostream& outputStream, const Edge& edge);

#endif /* EDGE_H */

