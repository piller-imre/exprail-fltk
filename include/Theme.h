#ifndef THEME_H
#define THEME_H

#include "Color.h"

#include <string>

/**
 * Represents the color theme of the diagram view.
 */
class Theme
{
public:

    /**
     * Construct the default theme.
     */
    Theme();

    /**
     * Use the theme which given by name.
     */
    void load(const std::string& themeName);

    /**
     * Set the values of the default theme.
     */
    void setDefaultValues();

    /**
     * Load the theme from the theme configuration file.
     */
    void loadThemeConfig(const std::string& path);

    /**
     * Get the curviness of the lines.
     */
    int curviness() const;

    /**
     * Get the background color of the canvas.
     */
    const Color& backgroundColor() const;

    /**
     * Get the color of the lines.
     */
    const Color& lineColor() const;

    /**
     * Get the color of the toolbar.
     */
    const Color& toolbarColor() const;

    /**
     * Get the color of the node labels.
     */
    const Color& nodeLabelColor() const;

    /**
     * Get the color of the error messages.
     */
    const Color& errorMessageColor() const;

protected:

    /**
     * Read parameter from the line of the config file.
     */
    void processConfigLine(const std::string& line);

private:

    /**
     * The curviness of the lines
     */
    int _curviness;

    /**
     * The background color of the canvas
     */
    Color _backgroundColor;

    /**
     * The color of the lines
     */
    Color _lineColor;

    /**
     * The color of the toolbar
     */
    Color _toolbarColor;

    /**
     * The color of the node labels
     */
    Color _nodeLabelColor;

    /**
     * The color of the error messages
     */
    Color _errorMessageColor;
};

#endif // THEME_H
