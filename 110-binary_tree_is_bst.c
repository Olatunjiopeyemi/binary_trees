#include "binary_trees.h"
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *tree, int low, int high);

/**
 * binary_tree_is_bst - A function that checks if a binary tree is a valid
 * Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 or 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - A function that checks if a binary tree is a valid binary
 * search tree.
 * @tree: The node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited this far.
 * Return: 1 or 0.
 */

int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}
