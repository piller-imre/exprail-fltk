#ifndef OPERATION_H
#define OPERATION_H

#include "Expression.h"
#include "Node.h"

// TODO: Use the mouse wheel!

/**
 * Operation types
 */
enum class OperationType
{
    NONE,
    CREATE_NODE,
    SELECT_NODE,
    SELECT_EDGE
};

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
     * Handle mouse and keyboard events.
     */
    void handleEvent(int event);

    /**
     * Check that the changing of operation is necessary.
     */
    bool needChangeOperation() const;

    /**
     * Get the type of the next operation.
     */
    OperationType getNextOperationType() const;

protected:

    /**
     * Handle mouse button press event.
     */
    virtual void pressMouse(MouseButton button, const Point& position);

    /**
     * Handle mouse button release event.
     */
    virtual void releaseMouse(MouseButton button, const Point& position);

    /**
     * Handle mouse move event.
     */
    virtual void moveMouse(const Point& position);

    /**
     * Handle mouse drag event.
     */
    virtual void dragMouse(MouseButton button, const Point& position);

    /**
     * Handle key press event.
     */
    virtual void pressKey(int key);

    /**
     * Handle key release event.
     */
    virtual void releaseKey(int key);

    /**
     * The edited expression
     */
    Expression* _expression;

    /**
     * The type of the next operation
     */
    OperationType _nextOperationType;

private:

    /**
     * Get the mouse button and position.
     */
    void getMouseEventData(MouseButton& mouseButton, Point& position) const;

    /**
     * Get the key code of keyboard event.
     */
    void getKeyEventData(int& key) const;

    /**
     * Remove the selected node.
     */
    void removeSelectedNode();

    /**
     * Rename the selected node.
     */
    void renameSelectedNode();
};

#endif /* OPERATION_H */

