#ifndef INDICATOR_H
#define INDICATOR_H

#include "Node.h"

/**
 * Indicator types
 */
enum class IndicatorType
{
    SELECTION,
    SOURCE,
    TARGET,
    SOURCE_ERROR,
    TARGET_ERROR,
    VALUE_ERROR
};

/**
 * Indicate some information about a node
 */
class Indicator
{
public:

    /**
     * Construct an empty indicator.
     */
    Indicator();

    /**
     * Construct an indicator for the given node.
     */
    Indicator(const Node& node);

    /**
     * Get the indicated node.
     */
    const Node& getNode() const;

    /**
     * Enable the source error flag of the indicator.
     */
    void enableSourceError();

    /**
     * Enable the target error flag of the indicator.
     */
    void enableTargetError();

    /**
     * Enable the value error flag of the indicator.
     */
    void enableValueError();

    /**
     * Returns with the source error flag.
     */
    bool hasSourceError() const;

    /**
     * Returns with the target error flag.
     */
    bool hasTargetError() const;

    /**
     * Returns with the value error flag.
     */
    bool hasValueError() const;

private:

    /**
     * The indicated node
     */
    Node _node;

    /**
     * Source error flag
     */
    bool _sourceError;

    /**
     * Target error flag
     */
    bool _targetError;

    /**
     * Value error flag
     */
    bool _valueError;
};

#endif /* INDICATOR_H */
