#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle for
 *
 * Return: Pointer to the uncle node, or NULL if there is no uncle
 *         or if node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the node is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* If the parent is the left child, return the right child of the grandparent */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	/* If the parent is the right child, return the left child of the grandparent */
	return (node->parent->parent->left);
}