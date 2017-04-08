#ifndef NODE_H
#define NODE_H

#include "Point.h"

#include <string>

/**
 * Node types of the expression graph
 */
enum class NodeType
{
    BEGIN,
    END,
    CONNECTION,
    SYMBOL,
    KEYWORD,
    EXPRESSION,
    SET,
    INFO,
    ERROR,
    TRANSFORMATION,
    OPERATION,
    STACK
};

/**
 * Represents a node in the expression graph
 */
class Node
{
public:

    /**
     * Construct a new node.
     */
    Node(NodeType type, const std::string& value, const Point& position);

    /**
     * Get the type of the node.
     */
    NodeType getType() const;

    /**
     * Set the type of the node.
     */
    void setType(NodeType type);

    /**
     * Get the value of the node.
     */
    std::string getValue() const;

    /**
     * Set the value of the node.
     */
    void setValue(const std::string& value);

    /**
     * Get the position of the node.
     */
    Point getPosition() const;

    /**
     * Set the position of the node.
     */
    void setPosition(const Point& position);

    /**
     * Check that the point is collided by the node icon.
     */
    bool hasCollision(const Point& point) const;

private:

    /**
     * The type of the node
     */
    NodeType _type;

    /**
     * The text value of the node
     */
    std::string _value;

    /**
     * The position of the node.
     */
    Point _position;
};

#endif /* NODE_H */

