#ifndef HANDLERS_H
#define HANDLERS_H

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Widget.H>

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
void browser_event_callback(Fl_Widget* widget, void*);

/**
 * Open a grammar file handler
 */
void open_grammar_callback(Fl_Widget* widget, void*);

/**
 * Save grammar to a file handler
 */
void save_grammar_callback(Fl_Widget* widget, void*);

/**
 * File chooser for opening handler
 */
void file_chooser_for_opening_callback(Fl_File_Chooser* widget, void*);

/**
 * File chooser for saving handler
 */
void file_chooser_for_saving_callback(Fl_File_Chooser* widget, void*);

#endif /* HANDLERS_H */
