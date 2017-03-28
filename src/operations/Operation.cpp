#include "operations/Operation.h"

Operation::Operation(Expression* expression)
{
    _expression = expression;
}

void Operation::pressMouse(MouseButton button, int x, int y)
{
}

void Operation::releaseMouse(MouseButton button, int x, int y)
{
}

void Operation::moveMouse(int x, int y)
{
}

void Operation::dragMouse(MouseButton button, int x, int y)
{
}

bool Operation::isCompleted() const
{
    return true;
}

