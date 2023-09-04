#include "binary_trees.h"
/**
 * binary_tree_postorder -A function that goes through a binary
 * by tree post-order traversal.
 * @tree: A pointer to the node
 * @func: A pointer to the calling function
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
