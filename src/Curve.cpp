#include "Curve.h"

#include <cassert>
#include <cmath>

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
    double t = 0.0;
    while (t < 1.0) {
        path.push_back(calcBernstein(t));
        t += 0.01;
    }
    return path;
}

Point Curve::calcBernstein(double t) const
{
    double x = 0.0;
    double y = 0.0;
    unsigned int n = _controlPoints.size() - 1;
    unsigned int i = 0;
    for (const Point& point : _controlPoints) {
        double q = calcChoose(n, i) * std::pow(1 - t, n - i) * std::pow(t, i);
        x += q * point.getX();
        y += q * point.getY();
        ++i;
    }
    return Point(x, y);
}

int Curve::calcChoose(int n, int k) const
{
    assert(k <= n);
    int r = 1;
    for (int d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

