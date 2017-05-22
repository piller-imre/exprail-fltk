#include "Editor.h"

#include "handlers.h"
#include "Parser.h"

#include "FL/fl_ask.H"

#include <cassert>
#include <fstream>

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

    createMenuBar();

    _addButton = new Fl_Button(10, 40, 50, 30, "Add");
    _removeButton = new Fl_Button(60, 40, 50, 30, "Remove");
    _upButton = new Fl_Button(110, 40, 50, 30, "Up");
    _downButton = new Fl_Button(160, 40, 50, 30, "Down");

    _addButton->callback(add_expression_callback);
    _removeButton->callback(remove_expression_callback);
    _upButton->callback(move_expression_up_callback);
    _downButton->callback(move_expression_down_callback);

    _browser = new Fl_Browser(10, 80, 200, 300);

    _browser->type(Fl_Browser::VERTICAL);
    _browser->callback(browser_event_callback);

    _expressionWindow->end();
}

void Editor::createMenuBar()
{
    _menuBar = new Fl_Menu_Bar(0, 0, 220, 24);
    _menuBar->add("File/Open", 0, open_grammar_callback);
    _menuBar->add("File/Save", 0, save_grammar_callback);
}

void Editor::createCanvas()
{
    _canvas = new Canvas(600, 400, "Graph");
}

void Editor::openGrammar()
{
    std::ifstream grammarFile;
    grammarFile.open(_grammarFilePath.c_str());
    _grammar = Parser::readGrammar(grammarFile);
    grammarFile.close();
    updateExpressionNameList();
}

void Editor::saveGrammar()
{
    std::ofstream grammarFile;
    grammarFile.open(_grammarFilePath.c_str());
    grammarFile << _grammar;
    grammarFile.close();
}

bool Editor::hasGrammarPath() const
{
    return _grammarFilePath != "";
}

void Editor::setGrammarPath(const std::string& path)
{
    _grammarFilePath = path;
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

void Editor::updateExpressionNameList()
{
    _browser->clear();
    for (const auto& item : _grammar.getExpressions()) {
        _browser->add(item.first.c_str());
    }
}
