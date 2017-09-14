#ifndef NODE_H
#define NODE_H

#include "Point.h"

#include <ostream>
#include <string>

/**
 * Node types of the expression graph
 */
enum class NodeType
{
    START,
    FINISH,
    CONNECTION,
    EXPRESSION,
    GROUND,
    TOKEN,
    EXCEPT_TOKEN,
    DEFAULT_TOKEN,
    ROUTER,
    EXCEPT_ROUTER,
    DEFAULT_ROUTER,
    INFO,
    ERROR,
    OPERATION,
    TRANSFORMATION,
    STACK,
    CLEAN
};

/**
 * Represents a node in the expression graph
 */
class Node
{
public:

    /**
     * Construct a new empty node.
     */
    Node();

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

    /**
     * Check that the value of the node is correct.
     */
    bool hasValueError() const;

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

/**
 * Write the content of the node to the output stream.
 */
std::ostream& operator<<(std::ostream& outputStream, const Node& node);

/**
 * Write the string version of the node type to the output stream.
 */
std::ostream& operator<<(std::ostream& outputStream, NodeType nodeType);

#endif /* NODE_H */

