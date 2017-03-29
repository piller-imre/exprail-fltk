#include "Expression.h"

Expression::Expression()
{
}

Node* Expression::searchFocusedNode(int x, int y)
{
    for (const std::unique_ptr<Node>& node : _nodes) {
        if (node->hasCollision(x, y)) {
            return node.get();
        }
    }
    return nullptr;
}

