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
    void createNewNode(int x, int y);

    /**
     * Use the focused node as selected node.
     */
    void useFocusedAsSelected(int x, int y);

    /**
     * Use the focused node as source node.
     */
    void useFocusedAsSource(int x, int y);

    /**
     * Use the focused node as target node.
     */
    void useFocusedAsTarget(int x, int y);

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
    void moveSelectedNode(int x, int y);

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

private:

    /**
     * Search the focused node.
     */
    Node* searchFocusedNode(int x, int y);

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
};

#endif /* EXPRESSION_H */

