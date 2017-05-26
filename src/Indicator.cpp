#include "Indicator.h"

Indicator::Indicator()
    : _sourceError(false), _targetError(false), _valueError(false)
{
}

Indicator::Indicator(const Node& node)
    : Indicator()
{
    _node = node;
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
