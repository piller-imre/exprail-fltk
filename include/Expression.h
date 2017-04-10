#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Connector.h"
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
     * Select the first connector.
     */
    void selectFirstConnector(const Point& position);

    /**
     * Select the second connector.
     */
    void selectSecondConnector(const Point& position);

    /**
     * Get the selected node.
     */
    const Node* getSelectedNode() const;

    /**
     * Get the first connector.
     */
    const Connector getFirstConnector() const;

    /**
     * Get the second connector.
     */
    const Connector getSecondConnector() const;

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
     * Search the focused connector.
     */
    Connector searchConnector(const Point& position);

    /**
     * Selected type for new node creation
     */
    NodeType _selectedNodeType;

    /**
     * The selected node
     */
    Node* _selectedNode;

    /**
     * The first connector for edge selection
     */
    Connector _firstConnector;

    /**
     * The second connector for edge selection
     */
    Connector _secondConnector;

    /**
     * Origin of the expression graph own coordinate system
     */
    Point _origin;
};

#endif /* EXPRESSION_H */

