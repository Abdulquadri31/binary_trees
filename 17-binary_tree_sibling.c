#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling for
 *
 * Return: Pointer to the sibling node, or NULL if there is no sibling
 *         or if node is NULL or the parent is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the node or its parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If the node is the left child, return the right child (sibling) */
	if (node == node->parent->left)
		return (node->parent->right);

	/* If the node is the right child, return the left child (sibling) */
	return (node->parent->left);
}
