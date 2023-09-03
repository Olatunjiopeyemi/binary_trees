#include "binary_trees.h"
/**
 * binary_tree_depth - A function that measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure
 * Return: 0 or depth of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}