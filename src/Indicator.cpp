#include "Indicator.h"

Indicator::Indicator()
    : _sourceError(false), _targetError(false), _valueError(false), _defaultRouteError(false)
{
}

Indicator::Indicator(const Node& node)
    : Indicator()
{
    _node = node;
}

const Node& Indicator::getNode() const
{
    return _node;
}

void Indicator::enableSourceError()
{
    _sourceError = true;
}

void Indicator::enableTargetError()
{
    _targetError = true;
}

void Indicator::enableValueError()
{
    _valueError = true;
}

void Indicator::enableDefaultRouteError()
{
    _defaultRouteError = true;
}

bool Indicator::hasSourceError() const
{
    return _sourceError;
}

bool Indicator::hasTargetError() const
{
    return _targetError;
}

bool Indicator::hasValueError() const
{
    return _valueError;
}

bool Indicator::hasDefaultRouteError() const
{
    return _defaultRouteError;
}
