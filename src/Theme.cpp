#include "Theme.h"

#include <fstream>
#include <sstream>

Theme::Theme()
{
    setDefaultValues();
}

void Theme::load(const string& themeName)
{
    setDefaultValues();
    std::stringstream stream;
    stream << "/tmp/" << themeName << "/theme.conf";
    loadThemeConfig(stream.str());
}

void Theme::setDefaultValues()
{
    _curviness = 64;
    _backgroundColor = Color(255, 255, 255);
    _lineColor = Color(60, 60, 60);
    _toolbarColor = Color(200, 200, 200);
    _nodeLabelColor = Color(0, 0, 200);
    _errorMessageColor = Color(200, 0, 0);
}

void Theme::loadThemeConfig(const std::string& path)
{
    std::ifstream configFile(path);
    std::string line;
    while (std::getline(configFile, line)) {
        processConfigLine(line);
    }
}

int Theme::curviness() const
{
    return _curviness;
}

const Color&Theme::backgroundColor() const
{
    return _backgroundColor;
}

const Color&Theme::lineColor() const
{
    return _lineColor;
}

const Color&Theme::toolbarColor() const
{
    return _toolbarColor;
}

const Color&Theme::nodeLabelColor() const
{
    return _nodeLabelColor;
}

const Color&Theme::errorMessageColor() const
{
    return _errorMessageColor;
}

void Theme::processConfigLine(const std::string& line)
{
    // TODO: Process the line.
}
