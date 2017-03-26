#ifndef NODE_H
#define NODE_H

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
    Node(NodeType type, const std::string& value, int x, int y);

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
     * Get the x coordinate of the position.
     */
    int getX() const;

    /**
     * Get the y coordinate of the position.
     */
    int getY() const;

    /**
     * Change the node position.
     */
    void move(int x, int y);

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
    int _x;
    int _y;
};

#endif /* NODE_H */

