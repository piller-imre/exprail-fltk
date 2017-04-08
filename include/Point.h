#ifndef POINT_H
#define POINT_H

/**
 * Represents a two dimensional point.
 */
class Point
{
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

private:

    /**
     * The coordinates of the point
     */
    int _x;
    int _y;
};

#endif /* POINT_H */

