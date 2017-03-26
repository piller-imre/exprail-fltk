#include "Canvas.h"

#include <FL/Fl.H>

#include <FL/fl_draw.H>

// DEBUG
#include <iostream>
using namespace std;
//

Canvas::Canvas(int width, int height, const char* title)
		: Fl_Double_Window(width, height, title)
{
    color(FL_WHITE);
    resizable(this);
    loadNodeImages();
}

void Canvas::draw()
{
    Fl_Double_Window::draw();
    drawMenuBar();
}

void Canvas::drawMenuBar() const
{
    fl_rectf(0, 0, 384, 32, FL_GRAY);
    _nodeImages->draw(0, 0);
}

int Canvas::handle(int event)
{
    int button;
    int mouseX, mouseY;

    if (isMouseEvent(event)) {
        getMouseEventData(&button, &mouseX, &mouseY);
        cout << "Button " << button << " at (" << mouseX << ", " << mouseY << ")" << endl;
    }

    switch (event) {
    case FL_PUSH:
        break;
    case FL_DRAG:
        break;
    case FL_RELEASE:
        break;
    case FL_MOVE:
        break;
    }
    return 1;
}

bool Canvas::isMouseEvent(int event) const
{
    return event == FL_PUSH
        || event == FL_DRAG
        || event == FL_RELEASE
        || event == FL_MOVE;
}

void Canvas::getMouseEventData(int* button, int* mouseX, int* mouseY) const
{
    *button = Fl::event_button();
    *mouseX = Fl::event_x();
    *mouseY = Fl::event_y();
}

void Canvas::loadNodeImages()
{
    _nodeImages = new Fl_PNG_Image("/tmp/nodes.png");
}

