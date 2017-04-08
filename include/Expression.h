#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Graph.h"

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
     * Copy expression on assignment.
     */
    Expression& operator=(const Expression& other);

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
     * Use the focused node as source node.
     */
    void useFocusedAsSource(const Point& position);

    /**
     * Use the focused node as target node.
     */
    void useFocusedAsTarget(const Point& position);

    /**
     * Get the selected node.
     */
    const Node* getSelectedNode() const;

    /**
     * Get the source node.
     */
    const Node* getSourceNode() const;

    /**
     * Get the target node.
     */
    const Node* getTargetNode() const;

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
     * Search the focused node.
     */
    Node* searchFocusedNode(const Point& position);

    /**
     * Selected type for new node creation
     */
    NodeType _selectedNodeType;

    /**
     * The selected node
     */
    Node* _selectedNode;

    /**
     * The source node of the edge selection
     */
    Node* _sourceNode;

    /**
     * The target node of the edge selection
     */
    Node* _targetNode;

    /**
     * Origin of the expression graph own coordinate system
     */
    Point _origin;
};

#endif /* EXPRESSION_H */

