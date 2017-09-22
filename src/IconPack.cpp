#include "IconPack.h"

#include "Parser.h"

#include <fstream>
#include <sstream>
#include <string>

IconPack::IconPack()
{
    load();
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

void IconPack::load()
{
    loadNodeIcons();
    loadCustomNodeIcons();
    loadIndicatorIcons();
}

void IconPack::loadNodeIcons()
{
    for (int i = 0; i < 17; ++i) {
        NodeType type = static_cast<NodeType>(i);
        std::stringstream pathStream;
        pathStream << "theme/icons/nodes/" << type << ".png";
        Fl_PNG_Image* image = loadIcon(pathStream.str());
        _nodeIcons.push_back(image);
    }
}

void IconPack::loadCustomNodeIcons()
{
    // TODO: Check the format of the nodes.conf file!
    std::ifstream configFile("theme/nodes.conf");
    std::string line;
    while (std::getline(configFile, line)) {
        processCustomNodeLine(line);
    }
}

void IconPack::loadIndicatorIcons()
{
    std::vector<std::string> indicators = {
        "selection",
        "source",
        "target",
        "source_error",
        "target_error",
        "value_error",
        "default_error"
    };
    for (const std::string& indicator : indicators) {
        std::stringstream pathStream;
        pathStream << "theme/icons/indicators/" << indicator << ".png";
        Fl_PNG_Image* image = loadIcon(pathStream.str());
        _indicatorIcons.push_back(image);
    }
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
        pathStream << "theme/icons/custom-nodes/" << fileName;
        NodeType nodeType = Parser::calcNodeType(type);
        Fl_PNG_Image* image = new Fl_PNG_Image(pathStream.str().c_str());
        _customNodeIcons[nodeType][value] = image;
    }
}

Fl_PNG_Image* IconPack::loadIcon(const std::string& path)
{
    Fl_PNG_Image* image;
    // TODO: Check that the file exists!
    image = new Fl_PNG_Image(path.c_str());
    return image;
}
