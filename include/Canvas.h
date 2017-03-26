#ifndef CANVAS_H
#define CANVAS_H

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_PNG_Image.H>

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

    /**
     * Load node images from nodes.png file.
     */
    void loadNodeImages();

    /**
     * Draw the menu bar.
     */
    void drawMenuBar() const;

    /**
     * Node images
     */
	Fl_PNG_Image* _nodeImages;
};

#endif /* CANVAS_H */

