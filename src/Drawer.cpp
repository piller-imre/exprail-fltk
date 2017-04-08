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

void Drawer::setOrigin(int x, int y)
{
    _x = x;
    _y = y;
}

void Drawer::drawLine(int x1, int y1, int x2, int y2) const
{
    fl_line(_x + x1, _y + y1, _x + x2, _y + y2);
}

void Drawer::drawRectangle(int x, int y, int width, int height) const
{
    fl_rect(_x + x, _y + y, width, height);
}

void Drawer::drawCricle(int x, int y, int radius) const
{
    int diameter = 2 * radius;
    fl_arc(_x + x - radius, _y + y - radius, diameter, diameter, 0, 360); 
}

void Drawer::drawIcon(int index, int x, int y) const
{
    _iconImage->draw(_x + x, _y + y, 32, 32, index * 32, 0);
}

void Drawer::drawText(const std::string& text, int x, int y) const
{
    fl_draw(text.c_str(), _x + x, _y + y);
}

