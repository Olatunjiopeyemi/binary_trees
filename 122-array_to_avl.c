#include "binary_trees.h"

/**
 * array_to_avl - A function that builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 * Return: A pointer to the node of the created AVL tree or NULL
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, i;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (i = 0; i < index; i++)
		{
			if (array[i] == array[index])
				break;
		}
		if (i == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
