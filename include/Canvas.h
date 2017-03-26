#ifndef CANVAS
#define CANVAS

#include <FL/Fl_Double_Window.H>

// TODO: Use the mouse wheel!

/**
 * Canvas for draw end editing the expression graphs.
 */
class Canvas : public Fl_Double_Window
{
public:

    /**
     * Construct a new canvas.
     */
	Canvas(int width, int height, const char* title);

    /**
     * Draw the expression graph.
     */
	virtual void draw();

    /**
     * Handle the events.
     */
	virtual int handle(int event);

private:

    /**
     * Check that the event is a mouse event.
     */
    bool isMouseEvent(int event) const;

    /**
     * Get the mouse position.
     */
    void getMouseEventData(int* button, int* mouseX, int* mouseY) const;
};

#endif /* CANVAS */

