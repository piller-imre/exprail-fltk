#include "Validator.h"

std::vector<std::string> Validator::validate(const Expression& expression)
{
    std::vector<std::string> errorMessages;

    checkStartNode(expression, errorMessages);
    checkFinishNodes(expression, errorMessages);
    checkGroundNode(expression, errorMessages);

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

void Validator::checkStartNode(const Expression& expression, std::vector<std::string>& errorMessages)
{
    unsigned int nStartNodes = Validator::countNodesByType(expression, NodeType::START);
    if (nStartNodes == 0) {
        errorMessages.push_back("The start node is missing!");
    }
    else if (nStartNodes > 1) {
        errorMessages.push_back("There are too many start nodes!");
    }
}

void Validator::checkFinishNodes(const Expression& expression, std::vector<std::string>& errorMessages)
{
    unsigned int nFinishNodes = Validator::countNodesByType(expression, NodeType::FINISH);
    if (nFinishNodes == 0) {
        errorMessages.push_back("The finish node is missing!");
    }
}

void Validator::checkGroundNode(const Expression& expression, std::vector<std::string>& errorMessages)
{
    unsigned int nGroundNodes = Validator::countNodesByType(expression, NodeType::GROUND);
    if (nGroundNodes > 1) {
        errorMessages.push_back("There are too many ground nodes!");
    }
}
