#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Node.h"

/**
 * Left or right side of the node
 */
enum class Side
{
    LEFT,
    RIGHT
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
    Connector(Node* node, Side side);

private:

    /**
     * The node which has a connector
     */
    Node* _node;

    /**
     * The side of the node where the connector is connected
     */
    Side _side;
};

#endif /* CONNECTOR_H */

