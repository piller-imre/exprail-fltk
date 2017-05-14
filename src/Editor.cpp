#include "Editor.h"

#include "handlers.h"

#include "FL/fl_ask.H"

#include <cassert>

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
    _canvas = new Canvas(600, 400, "Graph");
}

void Editor::addExpression(const std::string& expressionName)
{
    try {
        _grammar.addExpression(expressionName, Expression());
        _browser->add(expressionName.c_str());
    }
    catch (const std::runtime_error& error) {
        fl_message(error.what());
    }
}

void Editor::selectExpression(const std::string& expressionName)
{
    try {
        _canvas->setExpression(&_grammar.getExpression(expressionName));
        _canvas->redraw();
    }
    catch (const std::runtime_error& error) {
        fl_message(error.what());
    }
}

void Editor::renameExpression(const std::string& oldName, const std::string& newName)
{
    try {
        _grammar.renameExpression(oldName, newName);
        selectExpression(newName);
    }
    catch (const std::runtime_error& error) {
        fl_message(error.what());
    }
}

void Editor::removeSelectedExpression()
{
    // TODO: Check that it is really remove the expression from the grammar!
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
