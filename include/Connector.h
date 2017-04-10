#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Node.h"

/**
 * Left or right side of the node
 */
enum class Side
{
    LEFT,
    RIGHT,
    INVALID
};

/**
 * The connection point of the node
 */
class Connector
{
public:

    /**
     * Construct an empty connector.
     */
    Connector();

    /**
     * Construct new connector.
     */
    Connector(int nodeId, Side side);

    /**
     * Get the node of the connector.
     */
    int getNodeId() const;

    /**
     * Get the side of the connector.
     */
    Side getSide() const;

    /**
     * Check that the connector is valid.
     */
    bool isValid() const;

private:

    /**
     * The node identifier which has a connector
     */
    int _nodeId;

    /**
     * The side of the node where the connector is connected
     */
    Side _side;
};

#endif /* CONNECTOR_H */

