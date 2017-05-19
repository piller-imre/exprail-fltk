#include "Grammar.h"

#include <sstream>
#include <stdexcept>

Grammar::Grammar()
{
}

void Grammar::addExpression(const std::string& name, const Expression& expression)
{
    if (_expressions.find(name) == _expressions.end()) {
        _expressions[name] = expression;
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
