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

private:

    /**
     * The control points of the curve
     */
    std::vector<Point> _controlPoints;
};

#endif /* CURVE_H */

