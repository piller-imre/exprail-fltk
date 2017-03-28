#ifndef OPERATION_H
#define OPERATION_H

#include "Expression.h"
#include "Node.h"

/**
 * Mouse buttons
 */
enum class MouseButton
{
    LEFT,
    RIGHT,
    MIDDLE
};

/**
 * Expression operation base class
 */
class Operation
{
public:

    /**
     * Construct a new operation for the expression.
     */
    Operation(Expression* expression);

    /**
     * Press down a mouse button.
     */
    virtual void pressMouse(MouseButton button, int x, int y);

    /**
     * Release up a mouse button.
     */
    virtual void releaseMouse(MouseButton button, int x, int y);

    /**
     * Move the mouse.
     */
    virtual void moveMouse(int x, int y);

    /**
     * Drag the mouse.
     */
    virtual void dragMouse(MouseButton button, int x, int y);

    /**
     * Check that the operation has completed.
     */
    virtual bool isCompleted() const;

protected:

    /**
     * The edited expression
     */
    Expression* _expression;

    /**
     * Sign that wether the operation has completed or not.
     */
    bool _isCompleted;
};

#endif /* OPERATION_H */

