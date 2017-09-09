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
     * Load the icon pack.
     */
    void load();

    /**
     * Load the node icons.
     */
    void loadNodeIcons();

    /**
     * Load the token icons.
     */
    void loadCustomNodeIcons();

    /**
     * Load the indicator icons.
     */
    void loadIndicatorIcons();

    /**
     * Process the line of the custom node config file.
     */
    void processCustomNodeLine(const std::string& line);

    /**
     * Load an icon from the given path.
     */
    Fl_PNG_Image* loadIcon(const std::string& path);

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
