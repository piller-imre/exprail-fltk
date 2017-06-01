#include "Grammar.h"

#include <algorithm>
#include <sstream>
#include <stdexcept>

Grammar::Grammar()
{
}

void Grammar::addExpression(const std::string& name, const Expression& expression)
{
    if (_expressions.find(name) == _expressions.end()) {
        _expressions[name] = expression;
        _expressionOrder.push_back(name);
    }
    else {
        std::stringstream message;
        message << "The expression name '" << name << "' already exists!";
        throw std::runtime_error(message.str());
    }
}

void Grammar::renameExpression(const std::string& oldName, const std::string& newName)
{
    // TODO: Use hasExpression method for checking that the expression name is valid!
    if (oldName != newName) {
        if (_expressions.find(newName) == _expressions.end()) {
            _expressions[newName] = _expressions[oldName];
            _expressions.erase(oldName);
            unsigned int nameIndex = calcExpressionIndex(oldName);
            _expressionOrder[nameIndex] = newName;
        }
        else {
            std::stringstream message;
            message << "The expression name '" << newName << "' already exists!";
            throw std::runtime_error(message.str());
        }
    }
}

void Grammar::removeExpression(const std::string& name)
{
    if (_expressions.find(name) != _expressions.end()) {
        _expressions.erase(name);
        std::vector<std::string>::iterator nameIterator = std::find(_expressionOrder.begin(), _expressionOrder.end(), name);
        _expressionOrder.erase(nameIterator, nameIterator + 1);
    }
    else {
        std::stringstream message;
        message << "The expression name '" << name << "' already exists!";
        throw std::runtime_error(message.str());
    }
}

Expression& Grammar::getExpression(const std::string& name)
{
    if (_expressions.find(name) != _expressions.end()) {
        return _expressions[name];
    }
    else {
        std::stringstream message;
        message << "The expression called '" << name << "' does not exists!";
        throw std::runtime_error(message.str());
    }
}

const std::map<std::string, Expression>& Grammar::getExpressions() const
{
    return _expressions;
}

const std::vector<std::string>& Grammar::getExpressionOrder() const
{
    return _expressionOrder;
}

void Grammar::moveExpressionDown(const std::string& name)
{
    unsigned int nameIndex = calcExpressionIndex(name);
    if (nameIndex + 1 < _expressionOrder.size()) {
        std::swap(_expressionOrder[nameIndex], _expressionOrder[nameIndex + 1]);
    }
}

void Grammar::moveExpressionUp(const std::string& name)
{
    unsigned int nameIndex = calcExpressionIndex(name);
    if (nameIndex > 0) {
        std::swap(_expressionOrder[nameIndex], _expressionOrder[nameIndex - 1]);
    }
}

unsigned int Grammar::calcExpressionIndex(const std::string& name) const
{
    std::vector<std::string>::const_iterator nameIterator = std::find(_expressionOrder.begin(), _expressionOrder.end(), name);
    if (nameIterator == _expressionOrder.end()) {
        std::stringstream errorMessage;
        errorMessage << "The expression '" << name << "' is missing!";
        throw std::runtime_error(errorMessage.str());
    }
    unsigned int nameIndex = nameIterator - _expressionOrder.begin();
    return nameIndex;
}

std::ostream& operator<<(std::ostream& outputStream, const Grammar& grammar)
{
    for (auto const& item : grammar.getExpressions()) {
        outputStream << "expression \"";
        for (char c : item.first) {
            if (c == '"' || c == '\\') {
                outputStream << '\\';
            }
            outputStream << c;
        }
        outputStream << "\"" << std::endl;
        outputStream << item.second << std::endl;
    }
    return outputStream;
}
