#ifndef ICONPACK_H
#define ICONPACK_H

#include "Indicator.h"
#include "Node.h"

#include <FL/Fl_PNG_Image.H>

#include <map>
#include <string>
#include <utility>
#include <vector>

/**
 * Collection of the icon resources
 */
class IconPack
{
public:

    /**
     * Constructs an empty pack.
     */
    IconPack();

    /**
     * Free the allocated icons.
     */
    ~IconPack();

    /**
     * Use the icon pack given by name.
     */
    void load(const std::string& name);

    /**
     * Get a node image from the icon pack.
     */
    Fl_PNG_Image* getNodeImage(const Node& node) const;

    /**
     * Get an indicator image from the icon pack.
     */
    Fl_PNG_Image* getIndicatorImage(IndicatorType indicatorType) const;

    /**
     * Check that is there any custom node icon for the node.
     */
    bool isCustomNode(const Node& node) const;

protected:

    /**
     * Load the node icons of the given theme.
     */
    void loadNodeIcons(const std::string& name);

    /**
     * Load the token icons of the given theme.
     */
    void loadCustomNodeIcons(const std::string& name);

    /**
     * Load the indicator icons of the given theme.
     */
    void loadIndicatorIcons(const std::string& name);

    /**
     * Process the line of the custom node config file.
     */
    void processCustomNodeLine(const std::string& line);

    /**
     * Load an icon from the given directory by name.
     */
    Fl_PNG_Image* loadIcon(const std::string& directory, const std::string& name);

private:

    /**
     * Icon images
     */
    std::vector<Fl_PNG_Image*> _nodeIcons;

    /**
     * Indicator images
     */
    std::vector<Fl_PNG_Image*> _indicatorIcons;

    /**
     * Custom node images
     */
    std::map<NodeType, std::map<std::string, Fl_PNG_Image*>> _customNodeIcons;
};

#endif // ICONPACK_H
