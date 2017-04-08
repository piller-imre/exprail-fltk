#include "Node.h"

Node::Node(NodeType type, const std::string& value, const Point& position)
{
    setType(type);
    setValue(value);
    setPosition(position);
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

Point Node::getPosition() const
{
    return _position;
}

void Node::setPosition(const Point& position)
{
    _position = position;
}

bool Node::hasCollision(const Point& point) const
{
    // TODO: Use rounded area!
    if (point.getX() >= _position.getX() - 16
        && point.getX() < _position.getX() + 16
        && point.getY() >= _position.getY() - 16
        && point.getY() < _position.getY() + 16
    ) {
        return true;
    }
    return false;
}

