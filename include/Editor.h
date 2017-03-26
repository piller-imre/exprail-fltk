#ifndef EDITOR_H
#define EDITOR_H

#include <FL/Fl.H>

#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

#include <string>

#include "Canvas.h"

/**
 * Expression editor
 */
class Editor
{
public:

    /**
     * Construct new editor.
     */
    Editor();

    /**
     * Destruct the editor.
     */
    ~Editor();

    /**
     * Create new expression window.
     */
    void createExpressionWindow();

    /**
     * Create new canvas window.
     */
    void createCanvas();

    /**
     * Add new expression.
     */
    void addExpression(const std::string& expressionName);

    /**
     * Rename the selected expression.
     */
    void renameSelectedExpression(const std::string& expressionName);

    /**
     * Remove the selected expression.
     */
    void removeSelectedExpression();

    /**
     * Move the selected expression up in the list.
     */
    void moveSelectedExpressionUp();

    /**
     * Move the selected expression down in the list.
     */
    void moveSelectedExpressionDown();

    /**
     * Run the editor event loop.
     */
    int run();

private:

    /**
     * Expression browser window
     */
    Fl_Window* _expressionWindow;

    /**
     * Buttons for expression list operations
     */
    Fl_Button* _addButton;
    Fl_Button* _removeButton;
    Fl_Button* _upButton;
    Fl_Button* _downButton;

    /**
     * Expression list browser
     */
    Fl_Browser* _browser;

    /**
     * Graph editor canvas
     */
    Canvas* _canvas;
};

#endif /* EDITOR_H */

