#include "binary_trees.h"
 /**
 * binary_tree_node - Creating a binary tree node
 * @parent: A pointer to the parent node.
 * @value: The value of the new node
 * Return: A pointer to the new node if successful
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *current;

	current = malloc(sizeof(binary_tree_t));
	if (current == NULL)
		return (NULL);

	current->n = value;
	current->parent = parent;
	current->left = NULL;
	current->right = NULL;

	return (current);
}
