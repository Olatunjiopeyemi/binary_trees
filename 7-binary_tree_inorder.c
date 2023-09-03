#include "binary_trees.h"
/**
 * binary_tree_inorder - A function that goes through a binary tree using in-order traversal.
 * @tree: A pointer to the node
 * @func: A pointer that calling function
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
