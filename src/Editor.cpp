#include "Editor.h"

#include "handlers.h"


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

    _browser->type(Fl_Browser::VERTICAL);
    _browser->callback(browser_event_callback);

    _expressionWindow->end();
}

void Editor::createCanvas()
{
    _canvas = new Fl_Double_Window(600, 400, "Graph");
    _canvas->resizable(_canvas);
}

void Editor::addExpression(const std::string& expressionName)
{
    _browser->add(expressionName.c_str());
}

void Editor::removeSelectedExpression()
{
    int selectedLine = _browser->value();
    if (selectedLine > 0) {
        // TODO: Add confirmation window!
        _browser->remove(selectedLine);
    }
}

void Editor::moveSelectedExpressionUp()
{
    int selectedLine = _browser->value();
    if (selectedLine > 1) {
        _browser->move(selectedLine, selectedLine - 1);
    }
}

void Editor::moveSelectedExpressionDown()
{
    int selectedLine = _browser->value();
    if (selectedLine > 0) {
        _browser->move(selectedLine, selectedLine + 1);
    }
}

int Editor::run()
{
    _expressionWindow->show();
    _canvas->show();

    return Fl::run();
}

