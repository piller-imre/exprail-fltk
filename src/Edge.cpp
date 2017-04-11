#include "Edge.h"

Edge::Edge(const Connector& first, const Connector& second)
{
    _first = first;
    _second = second;
}

Connector Edge::getFirst() const
{
    return _first;
}

Connector Edge::getSecond() const
{
    return _second;
}

bool Edge::operator==(const Edge& other) const
{
    if (_first == other._first && _second == other._second) {
        return true;
    }
    else if (_first == other._second && _second == other._first) {
        return true;
    }
    return false;
}

bool Edge::operator!=(const Edge& other) const
{
    return !(*this == other);
}

