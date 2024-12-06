#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
	const binary_tree_t *temp_first, *temp_second;

	/* Return NULL if either node is NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	temp_first = first;
	temp_second = second;

	/* Traverse upwards from both nodes until they meet */
	while (temp_first != temp_second)
	{
		/* If temp_first reaches NULL, start from the second node */
		temp_first = (temp_first == NULL) ? second : temp_first->parent;
		/* If temp_second reaches NULL, start from the first node */
		temp_second = (temp_second == NULL) ? first : temp_second->parent;
	}

	/* Return the common ancestor */
	return ((binary_tree_t *)temp_first);
}
