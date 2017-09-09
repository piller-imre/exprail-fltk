#include "IconPack.h"

#include "Parser.h"

#include <fstream>
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
    for (auto &item : _customNodeIcons) {
        for (auto icon : item.second) {
            delete icon.second;
        }
    }
}

void IconPack::load(const std::string& name)
{
    loadNodeIcons(name);
    loadCustomNodeIcons(name);
    loadIndicatorIcons(name);
}

Fl_PNG_Image* IconPack::getNodeImage(const Node& node) const
{
    Fl_PNG_Image* image;
    try {
        image = _customNodeIcons.at(node.getType()).at(node.getValue());
    }
    catch (const std::out_of_range&) {
        int nodeIndex = static_cast<int>(node.getType());
        image = _nodeIcons[nodeIndex];
    }
    return image;
}

Fl_PNG_Image* IconPack::getIndicatorImage(IndicatorType indicatorType) const
{
    int indicatorIndex = static_cast<int>(indicatorType);
    return _indicatorIcons[indicatorIndex];
}

bool IconPack::isCustomNode(const Node &node) const
{
    try {
        _customNodeIcons.at(node.getType()).at(node.getValue());
        return true;
    }
    catch (const std::out_of_range&) {
        return false;
    }
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

void IconPack::loadCustomNodeIcons(const std::string& name)
{
    // TODO: Check the format of the nodes.conf file!
    std::stringstream stream;
    stream << "/tmp/" << name << "/nodes.conf";
    std::ifstream configFile(stream.str());
    std::string line;
    while (std::getline(configFile, line)) {
        processCustomNodeLine(line);
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

void IconPack::processCustomNodeLine(const std::string &line)
{
    std::string type;
    std::string value;
    std::string fileName;
    std::stringstream stream(line);
    stream >> type;
    stream >> value;
    stream >> fileName;
    if (type.empty() == false) {
        std::stringstream pathStream;
        pathStream << "/tmp/default/icons/custom-nodes/" << fileName;
        NodeType nodeType = Parser::calcNodeType(type);
        Fl_PNG_Image* image = new Fl_PNG_Image(pathStream.str().c_str());
        _customNodeIcons[nodeType][value] = image;
    }
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
