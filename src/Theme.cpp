#include "Theme.h"

#include <fstream>
#include <sstream>

Theme::Theme()
{
    setDefaultValues();
    load();
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

void Theme::load()
{
    setDefaultValues();
    std::stringstream stream;
    stream << "theme/theme.conf";
    loadThemeConfig(stream.str());
}

void Theme::processConfigLine(const std::string& line)
{
    std::string key;
    std::string value;
    std::stringstream stream(line);
    stream >> key;
    stream >> value;
    if (key == "curviness") {
        _curviness = std::stoi(value);
    }
    else if (key == "background-color") {
        _backgroundColor = Color(value);
    }
    else if (key == "line-color") {
        _lineColor = Color(value);
    }
    else if (key == "toolbar-color") {
        _toolbarColor = Color(value);
    }
    else if (key == "node-label-color") {
        _nodeLabelColor = Color(value);
    }
    else if (key == "error-message-color") {
        _errorMessageColor = Color(value);
    }
}
