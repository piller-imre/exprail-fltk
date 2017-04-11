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

bool Connector::operator==(const Connector& other) const
{
    if (_nodeId == other._nodeId && _side == other._side) {
        return true;
    }
    return false;
}

bool Connector::operator!=(const Connector& other) const
{
    return !(*this == other);
}

