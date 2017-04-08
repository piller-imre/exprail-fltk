#include "Point.h"

Point::Point(int x, int y)
{
    setX(x);
    setY(y);
}

int Point::getX() const
{
    return _x;
}

int Point::getY() const
{
    return _y;
}

void Point::setX(int x)
{
    _x = x;
}

void Point::setY(int y)
{
    _y = y;
}

