#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserting a node as the rightside of a node.
 * @parent: A pointer to the node to insert
 * @value: The value stored in the new node.
 * Return: NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *curr;

	if (parent == NULL)
		return (NULL);

	curr = binary_tree_node(parent, value);
	if (curr == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		curr->right = parent->right;
		parent->right->parent = curr;
	}
	parent->right = curr;

	return (curr);
}
