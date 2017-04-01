#ifndef SELECT_NODE_OPERATION_H
#define SELECT_NODE_OPERATION_H

#include "operations/Operation.h"

/**
 * Operation for selecting and grabbing the nodes
 */
class SelectNodeOperation : public Operation
{
public:

    /**
     * Construct a new select node operation.
     */
    SelectNodeOperation(Expression* expression);

    /**
     * Select a node or deselect the selected one.
     */
    virtual void pressMouse(MouseButton button, int x, int y);

    /**
     * Drag the selected node
     */
    virtual void dragMouse(MouseButton button, int x, int y);

private:

    /**
     * The previous position of the mouse cursor
     */
    int _prevX;
    int _prevY;
};

#endif /* SELECT_NODE_OPERATION_H */

