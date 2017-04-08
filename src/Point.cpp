#include "Point.h"

Point::Point()
{
    setX(0);
    setY(0);
}

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

Point Point::operator+(const Point& point) const
{
    return Point(_x + point.getX(), _y + point.getY());
}

Point& Point::operator+=(const Point& delta)
{
    _x += delta.getX();
    _y += delta.getY();
    return *this;
}

Point Point::operator-(const Point& point) const
{
    return Point(_x - point.getX(), _y - point.getY());
}

Point& Point::operator-=(const Point& delta)
{
    _x -= delta.getX();
    _y -= delta.getY();
    return *this;
}

