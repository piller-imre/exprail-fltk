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
     * Construct a new operation.
     */
    CreateNodeOperation(Expression* expression);

    /**
     * Create a new node on mouse button release.
     */
    virtual void releaseMouse(MouseButton button, const Point& position);
};

#endif /* CREATE_NODE_OPERATION_H */

