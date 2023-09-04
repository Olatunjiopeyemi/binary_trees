#include "binary_trees.h"
/**
 * binary_trees_ancestor - A function that finds the lowest common ancestor
 * of two nodes.
 * @first: The first node.
 * @second: The second node.
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *lead, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	lead = first->parent, pop = second->parent;
	if (first == pop || !lead || (!lead->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (lead == second || !pop || (!pop->parent && lead))
		return (binary_trees_ancestor(lead, second));

	return (binary_trees_ancestor(lead, pop));
}
