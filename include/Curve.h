#ifndef CURVE_H
#define CURVE_H

#include "Point.h"

#include <vector>

/**
 * Curve class for drawing rails
 */
class Curve
{
public:

    /**
     * Construct a curve without points.
     */
    Curve();

    /**
     * Add new control point to the curve.
     */
    void add(const Point& point);

    /**
     * Get the curve points as a path.
     */
    std::vector<Point> getPath() const;

protected:

    /**
     * Calculate the point with Bernstein polynom.
     */
    Point calcBernstein(double t) const;

    /**
     * Calculate the combination of (n, k).
     */
    int calcChoose(int n, int k) const;

private:

    /**
     * The control points of the curve
     */
    std::vector<Point> _controlPoints;
};

#endif /* CURVE_H */

