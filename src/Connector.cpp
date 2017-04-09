#include "Connector.h"

Connector::Connector()
{
    _node = nullptr;
    _side = Side::LEFT;
}

Connector::Connector(Node* node, Side side)
{
    _node = node;
    _side = side;
}

Node* Connector::getNode() const
{
    return _node;
}

Side Connector::getSide() const
{
    return _side;
}
