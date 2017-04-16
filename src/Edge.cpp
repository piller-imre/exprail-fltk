#include "Edge.h"

Edge::Edge(int sourceId, int targetId)
{
    _sourceId = sourceId;
    _targetId = targetId;
}

int Edge::getSourceId() const
{
    return _sourceId;
}

int Edge::getTargetId() const
{
    return _targetId;
}

bool Edge::operator==(const Edge& other) const
{
    if (_sourceId == other._sourceId && _targetId == other._targetId) {
        return true;
    }
    return false;
}

bool Edge::operator!=(const Edge& other) const
{
    return !(*this == other);
}

bool Edge::operator<(const Edge& other) const
{
    if (_sourceId < other._sourceId) {
        return true;
    }
    else if (_sourceId == other._sourceId && _targetId < other._targetId) {
        return true;
    }
    else {
        return false;
    }
}

