#include "Curve.h"

Curve::Curve()
{
}

void Curve::add(const Point& point)
{
    _controlPoints.push_back(point);
}

std::vector<Point> Curve::getPath() const
{
    std::vector<Point> path;
    path = _controlPoints;
    return path;
}

