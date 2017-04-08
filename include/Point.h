#ifndef POINT_H
#define POINT_H

/**
 * Represents a two dimensional point.
 */
class Point
{
public:

    /**
     * Construct zero point.
     */
    Point();

    /**
     * Construct new point.
     */
    Point(int x, int y);

    /**
     * Get the x coordinate.
     */
    int getX() const;

    /**
     * Get the y coordinate.
     */
    int getY() const;

    /**
     * Set the x coordinate.
     */
    void setX(int x);

    /**
     * Set the y coordinate.
     */
    void setY(int y);

    /**
     * Add points by coordinates.
     */
    Point operator+(const Point& point) const;

    /**
     * Shift the point with the given delta.
     */
    Point& operator+=(const Point& delta);

    /**
     * Subtract points by coordinates.
     */
    Point operator-(const Point& point) const;

    /**
     * Shift the point with the given delta with opposite direction.
     */
    Point& operator-=(const Point& delta);

private:

    /**
     * The coordinates of the point
     */
    int _x;
    int _y;
};

#endif /* POINT_H */

