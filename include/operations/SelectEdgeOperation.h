#ifndef SELECT_EDGE_OPERATION_H
#define SELECT_EDGE_OPERATION_H

#include "operations/Operation.h"

/**
 * Operation for selecting edges
 */
class SelectEdgeOperation : public Operation
{
public:

    /**
     * Construct new edge selector operation.
     */
    SelectEdgeOperation(Expression* expression);

    /**
     * Select the source/target nodes and toggle the edge.
     */
    virtual void pressMouse(MouseButton button, const Point& position) override;
};

#endif /* SELECT_EDGE_OPERATION_H */

