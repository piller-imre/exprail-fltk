#ifndef ICONPACK_H
#define ICONPACK_H

#include "Indicator.h"
#include "Node.h"

#include <FL/Fl_PNG_Image.H>

#include <map>
#include <string>
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
    Fl_PNG_Image* getNodeImage(NodeType nodeType) const;

    /**
     * Get an indicator image from the icon pack.
     */
    Fl_PNG_Image* getIndicatorImage(IndicatorType indicatorType) const;

    /**
     * Get a token image from the icon pack.
     */
    Fl_PNG_Image* getTokenImage(const std::string& tokenType) const;

    /**
     * Check that whether the given type is a custom token type.
     */
    bool isCustomToken(const std::string& tokenType) const;

protected:

    /**
     * Load the node icons of the given theme.
     */
    void loadNodeIcons(const std::string& name);

    /**
     * Load the indicator icons of the given theme.
     */
    void loadIndicatorIcons(const std::string& name);

    /**
     * Load the token icons of the given theme.
     */
    void loadTokenIcons(const std::string& name);

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
     * Token images
     */
    std::map<std::string, Fl_PNG_Image*> _tokenIcons;
};

#endif // ICONPACK_H
