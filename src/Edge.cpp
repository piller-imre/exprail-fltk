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

