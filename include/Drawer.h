#ifndef DRAWER_H
#define DRAWER_H

#include "Point.h"

#include <FL/Fl_PNG_Image.H>

#include <string>

/**
 * Draw primitives in the graphical context.
 */
class Drawer
{
public:

    /**
     * Construct a new drawer object.
     */
    Drawer();

    /**
     * Destruct the drawer object.
     */
    ~Drawer();

    /**
     * Set current color.
     */
    void setColor(int red, int green, int blue) const;

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
    void drawEdge(const Point& source, const Point& target) const;

    /**
     * Draw step-like curve.
     */
    void drawStepCurve(const Point& source, const Point& target) const;

    /**
     * Draw zigzag-like curve.
     */
    void drawZigzagCurve(const Point& source, const Point& target) const;

    /**
     * Draw shoe-like curve.
     */
    void drawShoeCurve(const Point& source, const Point& target) const;

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
     * Draw the icon image.
     */
    void drawIconImage(const Point& position) const;

    /**
     * Draw icon at the given position.
     */
    void drawIcon(int index, const Point& position) const;

    /**
     * Draw text at the given position.
     */
    void drawText(const std::string& text, const Point& position) const;

protected:

    /**
     * Icon image
     */
    Fl_PNG_Image* _iconImage;

    /**
     * The origin as the reference point
     */
    Point _origin;
};

#endif /* DRAWER_H */

