#ifndef COLOR_H
#define COLOR_H

#include <string>

/**
 * Represents a color in RGB color space.
 */
class Color
{
public:

    /**
     * Construct a black color.
     */
    Color();

    /**
     * Copy the color object.
     */
    Color(const Color& other);

    /**
     * Construct color from RGB channel values.
     */
    Color(int red, int green, int blue);

    /**
     * Construct a color from hexadecimal string format.
     *
     * NOTE: It assumes a # character at the beginning of the string!
     */
    Color(const std::string& hexCode);

    /**
     * Get the red component of the color.
     */
    int red() const;

    /**
     * Get the green component of the color.
     */
    int green() const;

    /**
     * Get the blue component of the color.
     */
    int blue() const;

private:

    /**
     * Color channel values
     */
    int _red;
    int _green;
    int _blue;
};

#endif // COLOR_H
