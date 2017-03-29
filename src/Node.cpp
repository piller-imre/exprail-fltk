#include "Node.h"

Node::Node(NodeType type, const std::string& value, int x, int y)
{
    setType(type);
    setValue(value);
    move(x, y);
}

NodeType Node::getType() const
{
    return _type;
}

void Node::setType(NodeType type)
{
    _type = type;
}

std::string Node::getValue() const
{
    return _value;
}

void Node::setValue(const std::string& value)
{
    _value = value;
}

int Node::getX() const
{
    return _x;
}

int Node::getY() const
{
    return _y;
}

void Node::move(int x, int y)
{
    _x = x;
    _y = y;
}

bool Node::hasCollision(int x, int y) const
{
    // TODO: Use rounded area!
    if (x >= _x - 16 && x < _x + 16 && y >= _y - 16 && y < _y + 16) {
        return true;
    }
    return false;
}

