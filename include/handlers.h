#ifndef HANDLERS
#define HANDLERS

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
void browser_event_callback(Fl_Widget* button, void*);

#endif /* HANDLERS */

