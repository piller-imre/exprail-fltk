#ifndef DRAWER_H
#define DRAWER_H

#include "Color.h"
#include "Indicator.h"
#include "Node.h"
#include "Point.h"

#include <FL/Fl_PNG_Image.H>

#include <string>
#include <vector>

/**
 * Draw primitives in the graphical context.
 */
class Drawer
{
public:

    /**
     * Set current color.
     */
    void setColor(int red, int green, int blue) const;

    /**
     * Set current color.
     */
    void setColor(const Color& color) const;

    /**
     * Set the origin of the graphical context.
     */
    void setOrigin(const Point& origin);

    /**
     * Draw line between the given points.
     */
    void drawLine(const Point& source, const Point& target) const;

    /**
     * Draw curved edge between two points.
     */
    void drawEdge(const Point& source, const Point& target, int curviness) const;

    /**
     * Draw step-like curve.
     */
    void drawStepCurve(const Point& source, const Point& target) const;

    /**
     * Draw zigzag-like curve.
     */
    void drawZigzagCurve(const Point& source, const Point& target, int curviness) const;

    /**
     * Draw shoe-like curve.
     */
    void drawShoeCurve(const Point& source, const Point& target, int curviness) const;

    /**
     * Draw path from the vector of points as a polyline.
     */
    void drawPath(const std::vector<Point>& points) const;

    /**
     * Draw a rectangle.
     */
    void drawRectangle(const Point& position, int width, int height) const;

    /**
     * Draw filled rectangle.
     */
    void fillRectangle(const Point& position, int width, int height) const;

    /**
     * Draw a circle.
     */
    void drawCircle(const Point& position, int radius) const;

    /**
     * Draw icon at the given position.
     */
    void drawIcon(Fl_PNG_Image* image, const Point& position) const;

    /**
     * Draw indicator background at the given position.
     */
    void drawIndicator(Fl_PNG_Image* image, const Point& position) const;

    /**
     * Draw text at the given position.
     */
    void drawText(const std::string& text, const Point& position) const;

    /**
     * Draw error message at the given position.
     */
    void drawMessage(const std::string& errorMessage, const Point& position) const;

protected:

    /**
     * The origin as the reference point
     */
    Point _origin;
};

#endif /* DRAWER_H */

