#include "Editor.h"

void browser_callback(Fl_Widget* widget, void*)
{
}

void canvas_callback(Fl_Widget* canvas, void*)
{
}

void add_expression_callback(Fl_Widget* button, void*)
{
}

void remove_expression_callback(Fl_Widget* button, void*)
{
}

void move_expression_up_callback(Fl_Widget* button, void*)
{
}

void move_expression_down_callback(Fl_Widget* button, void*)
{
}

void browser_event_callback(Fl_Widget* button, void*)
{
}

Editor::Editor()
{
	createExpressionWindow();
	createCanvas();
}

Editor::~Editor()
{
}

void Editor::createExpressionWindow()
{
	_expressionWindow = new Fl_Window(220, 400, "Expressions");
    _expressionWindow->resizable(_expressionWindow);

    _expressionWindow->begin();

    _addButton = new Fl_Button(10, 10, 50, 30, "Add");
    _removeButton = new Fl_Button(60, 10, 50, 30, "Remove");
    _upButton = new Fl_Button(110, 10, 50, 30, "Up");
    _downButton = new Fl_Button(160, 10, 50, 30, "Down");

    _addButton->callback(add_expression_callback);
    _removeButton->callback(remove_expression_callback);
    _upButton->callback(move_expression_up_callback);
    _downButton->callback(move_expression_down_callback);

    _browser = new Fl_Browser(10, 50, 200, 340);

    _browser->callback(browser_event_callback);

    _expressionWindow->end();
}

void Editor::createCanvas()
{
	_canvas = new Fl_Double_Window(600, 400, "Graph");
    _canvas->resizable(_canvas);
}

int Editor::run()
{
	_expressionWindow->show();
	_canvas->show();

    return Fl::run();
}

