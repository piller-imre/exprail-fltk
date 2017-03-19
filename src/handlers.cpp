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
    editor.addExpression(result);
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

void browser_event_callback(Fl_Widget* button, void*)
{
}

