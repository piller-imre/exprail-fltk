#ifndef EDITOR
#define EDITOR

#include <FL/Fl.H>

#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>

/**
 * Browser event handler
 */
void browser_callback(Fl_Widget* browser, void*);

/**
 * Canvas event handler
 */
void canvas_callback(Fl_Widget* canvas, void*);

/**
 * Add new expression handler
 */
void add_expression_callback(Fl_Widget* button, void*);

/**
 * Remove an expression handler
 */
void remove_expression_callback(Fl_Widget* button, void*);

/**
 * Move the expression up handler
 */
void move_expression_up_callback(Fl_Widget* button, void*);

/**
 * Move the expression down handler
 */
void move_expression_down_callback(Fl_Widget* button, void*);

/**
 * Browser event handler
 */
void browser_event_callback(Fl_Widget* button, void*);

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
    Fl_Double_Window* _canvas;
};

#endif /* EDITOR */

