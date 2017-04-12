#ifndef CANVAS_H
#define CANVAS_H

#include "Drawer.h"
#include "Expression.h"
#include "Node.h"
#include "operations/Operation.h"

#include <FL/Fl_Double_Window.H>

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
     * Draw the menu bar.
     */
    void drawMenuBar() const;

    /**
     * Draw the selected expression.
     */
    void drawExpression();

    /**
     * Draw the indicators.
     */
    void drawIndicators() const;

    /**
     * Indicate the selected node.
     */
    void indicateSelectedNode() const;

    /**
     * Indicate the selected source node.
     */
    void indicateSourceNode() const;

    /**
     * Indicate the selected target node.
     */
    void indicateTargetNode() const;

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
     * Drawer
     */
	Drawer drawer;

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

