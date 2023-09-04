#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that performs a left-rotation on a
 * binary tree.
 * @tree: The node of the tree to rotate.
 * Return: A pointer to the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *pivot, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	temp = pivot->left;
	pivot->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pivot;
		else
			temp->right = pivot;
	}

	return (pivot);
}
