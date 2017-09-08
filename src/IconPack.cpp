#include "IconPack.h"

#include <sstream>
#include <string>

IconPack::IconPack()
{
}

IconPack::~IconPack()
{
    for (Fl_PNG_Image* icon : _nodeIcons) {
        delete icon;
    }
    for (Fl_PNG_Image* icon : _indicatorIcons) {
        delete icon;
    }
    for (auto &item : _tokenIcons) {
        delete item.second;
    }
}

void IconPack::load(const std::string& name)
{
    loadNodeIcons(name);
    loadIndicatorIcons(name);
    loadTokenIcons(name);
}

Fl_PNG_Image* IconPack::getNodeImage(NodeType nodeType) const
{
    int nodeIndex = static_cast<int>(nodeType);
    return _nodeIcons[nodeIndex];
}

Fl_PNG_Image* IconPack::getIndicatorImage(IndicatorType indicatorType) const
{
    int indicatorIndex = static_cast<int>(indicatorType);
    return _indicatorIcons[indicatorIndex];
}

Fl_PNG_Image* IconPack::getTokenImage(const std::string& tokenType) const
{
    if (isCustomToken(tokenType)) {
        return _tokenIcons.at(tokenType);
    }
    return getNodeImage(NodeType::TOKEN);
}

bool IconPack::isCustomToken(const std::string& tokenType) const
{
    if (_tokenIcons.find(tokenType) != _tokenIcons.end()) {
        return true;
    }
    return false;
}

void IconPack::loadNodeIcons(const std::string& name)
{
    std::stringstream directory;
    directory << "/tmp/" << name << "/icons/nodes/";
    for (int i = 0; i < 14; ++i) {
        NodeType type = static_cast<NodeType>(i);
        std::stringstream name;
        name << type;
        Fl_PNG_Image* image = loadIcon(directory.str(), name.str());
        _nodeIcons.push_back(image);
    }
}

void IconPack::loadIndicatorIcons(const std::string& name)
{
    std::stringstream stream;
    stream << "/tmp/" << name << "/icons/indicators/";
    std::string directory = stream.str();
    _indicatorIcons.push_back(loadIcon(directory, "selection"));
    _indicatorIcons.push_back(loadIcon(directory, "source"));
    _indicatorIcons.push_back(loadIcon(directory, "target"));
    _indicatorIcons.push_back(loadIcon(directory, "source_error"));
    _indicatorIcons.push_back(loadIcon(directory, "target_error"));
    _indicatorIcons.push_back(loadIcon(directory, "value_error"));
}

void IconPack::loadTokenIcons(const std::string& name)
{
    // TODO: Use token.conf file instead of hard wired token type names!
    std::stringstream stream;
    stream << "/tmp/" << name << "/icons/tokens/";
    std::string directory = stream.str();
    _tokenIcons["0-9"] = loadIcon(directory, "0-9");
    _tokenIcons["a-Z"] = loadIcon(directory, "a-Z");
    _tokenIcons["ws"] = loadIcon(directory, "ws");
}

Fl_PNG_Image* IconPack::loadIcon(const std::string& directory, const std::string& name)
{
    Fl_PNG_Image* image;
    std::stringstream path;
    // TODO: Handle trailing slash in the directory path!
    path << directory << name << ".png";
    // TODO: Check that the file exists!
    image = new Fl_PNG_Image(path.str().c_str());
    return image;
}
