#ifndef EDITOR_H
#define EDITOR_H

#include "Canvas.h"
#include "Grammar.h"

#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>

#include <map>
#include <string>

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
     * Create the menu bar.
     */
    void createMenuBar();

    /**
     * Create new canvas window.
     */
    void createCanvas();

    /**
     * Open an existing grammar for editing.
     */
    void openGrammar();

    /**
     * Save the grammar to a file.
     */
    void saveGrammar();

    /**
     * Check that the path of the grammar file has set.
     */
    bool hasGrammarPath() const;

    /**
     * Set the path of the grammar file.
     */
    void setGrammarPath(const std::string& path);

    /**
     * Add new expression.
     */
    void addExpression(const std::string& expressionName);

    /**
     * Select the expression.
     */
    void selectExpression(const std::string& expressionName);

    /**
     * Rename the expression from old name to new name.
     */
    void renameExpression(const std::string& oldName, const std::string& newName);

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

protected:

    /**
     * Update the list of expression names in the expression window.
     */
    void updateExpressionNameList();

private:

    /**
     * Expression browser window
     */
    Fl_Window* _expressionWindow;

    /**
     * Menu bar
     */
    Fl_Menu_Bar* _menuBar;

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

    /**
     * The edited grammar
     */
    Grammar _grammar;

    /**
     * The path of the grammar file
     */
    std::string _grammarFilePath;
};

#endif /* EDITOR_H */
