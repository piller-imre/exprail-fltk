#include "handlers.h"

#include "Editor.h"

#include <FL/Fl_File_Chooser.H>

extern Editor editor;

void canvas_callback(Fl_Widget* canvas, void*)
{
}

void add_expression_callback(Fl_Widget* button, void*)
{
    const char* result = fl_input("Add new expression", "");
    if (result != nullptr) {
        // TODO: Check that the new name is valid!
        editor.addExpression(result);
    }
}

void remove_expression_callback(Fl_Widget* button, void*)
{
    editor.removeSelectedExpression();
}

void move_expression_up_callback(Fl_Widget* button, void*)
{
    editor.moveSelectedExpressionUp();
}

void move_expression_down_callback(Fl_Widget* button, void*)
{
    editor.moveSelectedExpressionDown();
}

void browser_event_callback(Fl_Widget* widget, void*)
{
    Fl_Browser* browser = (Fl_Browser*)widget;
    int selectedLine = browser->value();
    if (selectedLine > 0) {
        const char* name = browser->text(selectedLine);
        if (Fl::event_clicks() == 0) {
            editor.selectExpression(name);
        }
        else {
            const char* newName = fl_input("New name of the expression", name);
            if (newName != nullptr) {
                // TODO: Check that the name is valid!
                editor.renameExpression(name, newName);
                browser->text(selectedLine, newName);
            }
        }
    }
}

