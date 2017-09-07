#include "Color.h"

Color::Color() : _red(0), _green(0), _blue(0)
{
}

Color::Color(const Color& other)
{
    _red = other.red();
    _green = other.green();
    _blue = other.blue();
}

Color::Color(int red, int green, int blue): _red(red), _green(green), _blue(blue)
{
}

Color::Color(const std::string& hexCode)
{
    std::string redCode = hexCode.substr(1, 2);
    std::string greenCode = hexCode.substr(3, 2);
    std::string blueCode = hexCode.substr(5, 2);
    _red = std::stoi(redCode, nullptr, 16);
    _green = std::stoi(greenCode, nullptr, 16);
    _blue = std::stoi(blueCode, nullptr, 16);
}

int Color::red() const
{
    return _red;
}

int Color::green() const
{
    return _green;
}

int Color::blue() const
{
    return _blue;
}
