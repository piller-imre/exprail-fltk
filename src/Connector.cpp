#include "Connector.h"

Connector::Connector()
{
    _side = Side::INVALID;
}

Connector::Connector(int nodeId, Side side)
{
    _nodeId = nodeId;
    _side = side;
}

int Connector::getNodeId() const
{
    return _nodeId;
}

Side Connector::getSide() const
{
    return _side;
}

bool Connector::isValid() const
{
    return _side != Side::INVALID;
}

