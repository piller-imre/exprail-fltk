#include "Node.h"

Node::Node() : _type(NodeType::START)
{
}

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

bool Node::hasValueError() const
{
    switch (_type) {
    case NodeType::START:
    case NodeType::FINISH:
    case NodeType::CONNECTION:
    case NodeType::STACK:
    case NodeType::CLEAN:
    case NodeType::GROUND:
        if (_value == "") {
            return false;
        }
        break;
    default:
        if (_value != "") {
            return false;
        }
        break;
    }
    return true;
}

std::ostream& operator<<(std::ostream& outputStream, const Node& node)
{
    outputStream << node.getType() << " \"";
    for (char c : node.getValue()) {
        if (c == '"' || c == '\\') {
            outputStream << '\\';
        }
        outputStream << c;
    }
    outputStream << "\" ";
    outputStream << node.getPosition().getX() << " " << node.getPosition().getY();

    return outputStream;
}

std::ostream& operator<<(std::ostream& outputStream, NodeType nodeType)
{
    switch (nodeType) {
    case NodeType::START:
        outputStream << "start";
        break;
    case NodeType::FINISH:
        outputStream << "finish";
        break;
    case NodeType::CONNECTION:
        outputStream << "connection";
        break;
    case NodeType::EXPRESSION:
        outputStream << "expression";
        break;
    case NodeType::GROUND:
        outputStream << "ground";
        break;
    case NodeType::TOKEN:
        outputStream << "token";
        break;
    case NodeType::ROUTER:
        outputStream << "router";
        break;
    case NodeType::AVOID:
        outputStream << "avoid";
        break;
    case NodeType::INFO:
        outputStream << "info";
        break;
    case NodeType::ERROR:
        outputStream << "error";
        break;
    case NodeType::OPERATION:
        outputStream << "operation";
        break;
    case NodeType::TRANSFORMATION:
        outputStream << "transformation";
        break;
    case NodeType::STACK:
        outputStream << "stack";
        break;
    case NodeType::CLEAN:
        outputStream << "clean";
        break;
    }

    return outputStream;
}
