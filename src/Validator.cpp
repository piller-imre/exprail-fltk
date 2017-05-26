#include "Validator.h"

std::vector<std::string> Validator::validate(const Expression& expression)
{
    std::vector<std::string> errorMessages;

    unsigned int nStartNodes = Validator::countNodesByType(expression, NodeType::START);
    if (nStartNodes == 0) {
        errorMessages.push_back("The start node is missing!");
    }
    else if (nStartNodes > 1) {
        errorMessages.push_back("There are too many start nodes!");
    }

    unsigned int nFinishNodes = Validator::countNodesByType(expression, NodeType::FINISH);
    if (nFinishNodes == 0) {
        errorMessages.push_back("The finish node is missing!");
    }

    unsigned int nGroundNodes = Validator::countNodesByType(expression, NodeType::GROUND);
    if (nGroundNodes > 1) {
        errorMessages.push_back("There are too many ground nodes!");
    }

    return errorMessages;
}

unsigned int Validator::countNodesByType(const Expression& expression, NodeType nodeType)
{
    unsigned int count = 0;
    for (const auto& item : expression.getNodes()) {
        if (item.second.getType() == nodeType) {
            ++count;
        }
    }
    return count;
}
