#ifndef CANVAS_H
#define CANVAS_H

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_PNG_Image.H>

#include "Expression.h"
#include "Node.h"
#include "operations/Operation.h"

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
     * Set the editable expression.
     */
    void setExpression(Expression* expression);

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
     * Get the mouse button and position.
     */
    void getMouseEventData(MouseButton* mouseButton, int* mouseX, int* mouseY) const;

    /**
     * Load node images from nodes.png file.
     */
    void loadNodeImages();

    /**
     * Draw the menu bar.
     */
    void drawMenuBar() const;

    /**
     * Draw the selected expression.
     */
    void drawExpression() const;

    /**
     * Draw the edges of the expression graph.
     */
    void drawEdges() const;

    /**
     * Draw the nodes of the selected expression.
     */
    void drawNodes() const;

    /**
     * Draw node
     */
    void drawNode(const Node& node) const;

    /**
     * Node images
     */
	Fl_PNG_Image* _nodeImages;

    /**
     * The edited expression
     */
    Expression* _expression;

    /**
     * The current operation
     */
    Operation* _operation;
};

#endif /* CANVAS_H */

