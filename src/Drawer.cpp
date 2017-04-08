#include "Drawer.h"

#include <FL/fl_draw.H>

Drawer::Drawer()
{
    _iconImage = new Fl_PNG_Image("/tmp/nodes.png");
}

Drawer::~Drawer()
{
    delete _iconImage;
}

void Drawer::setColor(int red, int green, int blue) const
{
    fl_color(red, green, blue);
}

void Drawer::setOrigin(const Point& origin)
{
    _origin = origin;
}

void Drawer::drawLine(const Point& source, const Point& target) const
{
    Point p1 = _origin + source;
    Point p2 = _origin + target;
    fl_line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

void Drawer::drawRectangle(const Point& position, int width, int height) const
{
    Point p = _origin + position;
    fl_rect(p.getX(), p.getY(), width, height);
}

void Drawer::fillRectangle(const Point& position, int width, int height) const
{
    Point p = _origin + position;
    fl_rectf(p.getX(), p.getY(), width, height);
}

void Drawer::drawCircle(const Point& position, int radius) const
{
    Point p = _origin + position;
    int diameter = 2 * radius;
    fl_arc(p.getX() - radius, p.getY() - radius, diameter, diameter, 0, 360); 
}

void Drawer::drawIconImage(const Point& position) const
{
    Point p = _origin + position;
    _iconImage->draw(p.getX(), p.getY());
}

void Drawer::drawIcon(int index, const Point& position) const
{
    Point p = _origin + position;
    _iconImage->draw(p.getX(), p.getY(), 32, 32, index * 32, 0);
}

void Drawer::drawText(const std::string& text, const Point& position) const
{
    Point p = _origin + position;
    fl_draw(text.c_str(), p.getX(), p.getY());
}

