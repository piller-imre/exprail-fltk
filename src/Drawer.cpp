#include "Drawer.h"

#include "Curve.h"
#include "Node.h"
#include "Theme.h"

#include <FL/fl_draw.H>

#include <cmath>
#include <sstream>

Drawer::Drawer()
{
    loadNodeIcons();
    loadIndicatorIcons();
}

Drawer::~Drawer()
{
    for (Fl_PNG_Image* icon : _nodeIcons) {
        delete icon;
    }
    for (Fl_PNG_Image* icon : _indicatorIcons) {
        delete icon;
    }
}

void Drawer::loadNodeIcons()
{
    // TODO: Use theme path for further customization!
    std::stringstream stream;
    for (int i = 0; i < 14; ++i) {
        NodeType type = static_cast<NodeType>(i);
        stream.str(std::string());
        stream << "/tmp/default/icons/nodes/" << type << ".png";
        std::string path = stream.str();
        // TODO: Check that the file exists!
        Fl_PNG_Image* image = new Fl_PNG_Image(path.c_str());
        _nodeIcons.push_back(image);
    }
}

void Drawer::loadIndicatorIcons()
{
    // TODO: Check that the files exist!
    _indicatorIcons.push_back(new Fl_PNG_Image("/tmp/default/icons/indicators/selection.png"));
    _indicatorIcons.push_back(new Fl_PNG_Image("/tmp/default/icons/indicators/source.png"));
    _indicatorIcons.push_back(new Fl_PNG_Image("/tmp/default/icons/indicators/target.png"));
    _indicatorIcons.push_back(new Fl_PNG_Image("/tmp/default/icons/indicators/source_error.png"));
    _indicatorIcons.push_back(new Fl_PNG_Image("/tmp/default/icons/indicators/target_error.png"));
    _indicatorIcons.push_back(new Fl_PNG_Image("/tmp/default/icons/indicators/value_error.png"));
}

void Drawer::setColor(int red, int green, int blue) const
{
    fl_color(red, green, blue);
}

void Drawer::setColor(const Color& color) const
{
    fl_color(color.red(), color.green(), color.blue());
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

void Drawer::drawEdge(const Point& source, const Point& target, int curviness) const
{
    int distanceX = target.getX() - source.getX();
    int distanceY = target.getY() - source.getY();
    if (distanceX > curviness) {
        drawStepCurve(source, target);
    }
    else {
        if (std::abs(distanceY) < curviness) {
            drawShoeCurve(source, target, curviness);
        }
        else {
            drawZigzagCurve(source, target, curviness);
        }
    }
}

void Drawer::drawStepCurve(const Point& source, const Point& target) const
{
    int middleX = (source.getX() + target.getX()) / 2;
    Curve curve;
    curve.add(source);
    curve.add(Point(middleX, source.getY()));
    curve.add(Point(middleX, target.getY()));
    curve.add(target);
    drawPath(curve.getPath());
}

void Drawer::drawZigzagCurve(const Point& source, const Point& target, int curviness) const
{
    int middleY = (source.getY() + target.getY()) / 2;
    int sourceSideX = source.getX() + curviness;
    int targetSideX = target.getX() - curviness;
    Curve curve;
    curve.add(source);
    curve.add(Point(sourceSideX, source.getY()));
    curve.add(Point(sourceSideX, middleY));
    curve.add(Point(targetSideX, middleY));
    curve.add(Point(targetSideX, target.getY()));
    curve.add(target);
    drawPath(curve.getPath());
}

void Drawer::drawShoeCurve(const Point& source, const Point& target, int curviness) const
{
    int sourceSideX = source.getX() + curviness;
    int targetSideX = target.getX() - curviness;
    int supportY = target.getY();
    if (source.getY() < target.getY()) {
        supportY += curviness;
    }
    else {
        supportY -= curviness;
    }
    Curve curve;
    curve.add(source);
    curve.add(Point(sourceSideX, source.getY()));
    curve.add(Point(sourceSideX, supportY));
    curve.add(Point(targetSideX, supportY));
    curve.add(Point(targetSideX, target.getY()));
    curve.add(target);
    drawPath(curve.getPath());
}

void Drawer::drawPath(const std::vector<Point>& points) const
{
    for (unsigned int i = 0; i < points.size() - 1; ++i) {
        drawLine(points[i], points[i + 1]);
    }
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

void Drawer::drawIcons(const Point& position) const
{
    for (int i = 0; i < 14; ++i) {
        _nodeIcons[i]->draw(position.getX() + i * 32, position.getY(), 32, 32);
    }
}

void Drawer::drawIcon(NodeType nodeType, const Point& position) const
{
    Point p = _origin + position;
    int typeIndex = static_cast<int>(nodeType);
    _nodeIcons[typeIndex]->draw(p.getX(), p.getY(), 32, 32);
}

void Drawer::drawIndicator(IndicatorType indicatorType, const Point& position) const
{
    Point p = _origin + position;
    int index = static_cast<int>(indicatorType);
    _indicatorIcons[index]->draw(p.getX() - 32, p.getY() - 32, 64, 64);
}

void Drawer::drawText(const std::string& text, const Point& position) const
{
    Point p = _origin + position;
    fl_draw(text.c_str(), p.getX(), p.getY());
}

void Drawer::drawMessage(const std::string& message, const Point& position) const
{
    fl_draw(message.c_str(), position.getX(), position.getY());
}
