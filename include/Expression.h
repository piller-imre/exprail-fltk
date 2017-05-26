#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Graph.h"
#include "Indicator.h"

#include <cassert>
#include <vector>

/**
 * Represents the graph of an expression
 */
class Expression : public Graph
{
public:

    /**
     * Construct an empty expression graph.
     */
    Expression();

    /**
     * Construct new expression from nodes and edges.
     */
    Expression(const std::map<int, Node>& nodes, const std::set<Edge>& edges);

    /**
     * Add new node to the expression.
     */
    virtual void addNode(const Node& node) override;

    /**
     * Remove the given node.
     */
    virtual void removeNode(int nodeId) override;

    /**
     * Add new edge from the source to the target node.
     */
    virtual void addEdge(const Edge& edge) override;

    /**
     * Remove the edge from source node to target node.
     */
    virtual void removeEdge(const Edge& edge) override;

    /**
     * Select the type
     */
    void selectNodeType(NodeType nodeType);

    /**
     * Get the selected type
     */
    NodeType getSelectedNodeType() const;

    /**
     * Create new node at the given position.
     */
    void createNewNode(const Point& position);

    /**
     * Use the focused node as selected node.
     */
    void useFocusedAsSelected(const Point& position);

    /**
     * Select the source node.
     */
    void selectSourceNode(const Point& position);

    /**
     * Select the target node.
     */
    void selectTargetNode(const Point& position);

    /**
     * Get the identifier of the selected node.
     */
    int getSelectedNodeId() const;

    /**
     * Check that whether the expression has selected node or not.
     */
    bool hasSelectedNode() const;

    /**
     * Get the selected node.
     */
    const Node& getSelectedNode() const;

    /**
     * Get the identifier of the selected source node.
     */
    int getSourceNodeId() const;

    /**
     * Check that whether the expression has selected source node or not.
     */
    bool hasSourceNode() const;

    /**
     * Get the selected source node.
     */
    const Node& getSourceNode() const;

    /**
     * Get the identifier of the selected target node.
     */
    int getTargetNodeId() const;

    /**
     * Check that whether the expression has selected target node or not.
     */
    bool hasTargetNode() const;

    /**
     * Get the selected target node.
     */
    const Node& getTargetNode() const;

    /**
     * Move the selected node to the given position.
     */
    void moveSelectedNode(const Point& position);

    /**
     * Set the value of the selected node.
     */
    void setSelectedNodeValue(const std::string& value);

    /**
     * Remove the selected node.
     */
    void removeSelectedNode();

    /**
     * Toggle the edge between the source and target nodes.
     */
    void toggleSelectedEdge();

    /**
     * Shift the origin of the expression graph.
     */
    void shiftOrigin(const Point& delta);

    /**
     * Get the origin of the expression graph.
     */
    Point getOrigin() const;

private:

    /**
     * Search the identifier of the focused node.
     */
    int searchNode(const Point& position);

    /**
     * Update the node indicators.
     */
    void updateIndicators();

    /**
     * Selected type for new node creation
     */
    NodeType _selectedNodeType;

    /**
     * The identifier of the selected node
     */
    int _selectedNodeId;

    /**
     * The identifier of the selected source node
     */
    int _sourceNodeId;

    /**
     * The identifier of the selected target node
     */
    int _targetNodeId;

    /**
     * Origin of the expression graph own coordinate system
     */
    Point _origin;

    /**
     * The node indicators
     */
    std::vector<Indicator> _indicators;
};

/**
 * Write the content of the expression to the output stream.
 */
std::ostream& operator<<(std::ostream& outputStream, const Expression& expression);

#endif /* EXPRESSION_H */

