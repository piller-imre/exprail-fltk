#ifndef DRAWER_H
#define DRAWER_H

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
    void setOrigin(int x, int y);

    /**
     * Draw line between the given points.
     */
    void drawLine(int x1, int y1, int x2, int y2) const;

    /**
     * Draw a rectangle.
     */
    void drawRectangle(int x, int y, int width, int height) const;

    /**
     * Draw a circle.
     */
    void drawCricle(int x, int y, int radius) const;

    /**
     * Draw icon at the given position.
     */
    void drawIcon(int index, int x, int y) const;

    /**
     * Draw text at the given position.
     */
    void drawText(const std::string& text, int x, int y) const;

protected:

    /**
     * Icon image
     */
    Fl_PNG_Image* _iconImage;

    /**
     * Coordinates of the origin
     */
    int _x;
    int _y;
};

#endif /* DRAWER_H */

