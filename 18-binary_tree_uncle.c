#include "binary_trees.h"
/**
 * binary_tree_uncle - A function that finds the uncle of a node.
 * @node: The node to find the uncle.
 * Return: NULL if it doesnt have an uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
