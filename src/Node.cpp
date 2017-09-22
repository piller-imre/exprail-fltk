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
    case NodeType::DEFAULT_ROUTER:
    case NodeType::DEFAULT_TOKEN:
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

bool Node::isDefault() const
{
    if (_type == NodeType::DEFAULT_ROUTER
     || _type == NodeType::DEFAULT_TOKEN
     || _type == NodeType::FINISH) {
        return true;
    }
    return false;
}

bool Node::isMatchable() const
{
    if (_type == NodeType::ROUTER
     || _type == NodeType::EXCEPT_ROUTER
     || _type == NodeType::TOKEN
     || _type == NodeType::EXCEPT_TOKEN) {
        return true;
    }
    return false;
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
    case NodeType::EXCEPT_TOKEN:
        outputStream << "except_token";
        break;
    case NodeType::DEFAULT_TOKEN:
        outputStream << "default_token";
        break;
    case NodeType::ROUTER:
        outputStream << "router";
        break;
    case NodeType::EXCEPT_ROUTER:
        outputStream << "except_router";
        break;
    case NodeType::DEFAULT_ROUTER:
        outputStream << "default_router";
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
