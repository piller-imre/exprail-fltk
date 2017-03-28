#ifndef CREATE_NODE_OPERATION_H
#define CREATE_NODE_OPERATION_H

#include "operations/Operation.h"

/**
 * Operation for new node creation
 */
class CreateNodeOperation : public Operation
{
public:

    /**
     * Construct a new operation with the given node type.
     */
    CreateNodeOperation(Expression* expression, NodeType nodeType);

    /**
     * Create a new node on mouse button release.
     */
    virtual void releaseMouse(MouseButton button, int x, int y);

private:

    /**
     * The type of the created node
     */
    NodeType _nodeType;
};

#endif /* CREATE_NODE_OPERATION_H */

