#ifndef EDITOR
#define EDITOR

#include <FL/Fl.H>

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>

/**
 * Browser event handler
 */
void browser_callback(Fl_Widget* widget, void*);

/**
 * Canvas event handler
 */
void canvas_callback(Fl_Widget* canvas, void*);

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
     * Run the editor event loop.
     */
    int run();

private:

    /**
     * Expression browser
     */
    Fl_Window* _browser;

    /**
     * Graph editor canvas
     */
    Fl_Double_Window* _canvas;
};

#endif /* EDITOR */

