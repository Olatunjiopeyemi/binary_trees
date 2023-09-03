#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserting a node at the leftside of another node
 * @parent: A pointer to the new node
 * @value: The value stored in the new node.
 * Return: A pointer  to the new node or null
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *curr;

	if (parent == NULL)
		return (NULL);

	curr = binary_tree_node(parent, value);
	if (curr == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		curr->left = parent->left;
		parent->left->parent = curr;
	}
	parent->left = curr;

	return (curr);
}
