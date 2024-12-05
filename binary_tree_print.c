#include "binary_trees.h"
#include <stdio.h>
#include <stddef.h>

#define SPACE_COUNT 5

/**
 * print_tree - Recursive function to print the binary tree
 * @tree: Pointer to the current tree node
 * @space: The current level of indentation
 */
void print_tree(const binary_tree_t *tree, int space)
{
	int i;

	if (tree == NULL)
		return;

	space += SPACE_COUNT;

	/* Print right subtree first */
	print_tree(tree->right, space);

	/* Print current node after space count */
	printf("\n");
	for (i = SPACE_COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", tree->n);

	/* Print left subtree */
	print_tree(tree->left, space);
}

/**
 * binary_tree_print - Entry point to print the binary tree
 * @tree: Pointer to the root of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
	print_tree(tree, 0);
}
