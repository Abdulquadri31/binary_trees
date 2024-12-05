#include "binary_trees.h"

/**
 * depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the depth
 *
 * Return: The depth of the tree
 */
size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_helper - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @d: The depth of the tree
 * @level: The current level of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_helper(const binary_tree_t *tree, size_t d, size_t level)
{
	if (tree == NULL)
		return (1);

	/* If it's a leaf node, check if it is at the correct level */
	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	/* If it has only one child, it is not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recursively check both subtrees */
	return (is_perfect_helper(tree->left, d, level + 1) &&
		is_perfect_helper(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d;

	if (tree == NULL)
		return (0);

	/* Get the depth of the leftmost path */
	d = depth(tree);

	/* Check if the tree is perfect */
	return (is_perfect_helper(tree, d, 0));
}
