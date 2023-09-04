#include "binary_trees.h"
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
                levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);

/**
 * binary_tree_levelorder - A function that goes through a bin-tree by level-order traversal.
 * @tree: The node of the tree to traverse.
 * @func: A pointer to the calling function
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - The function that creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: NULL or a pointer to the new node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *n;

	n = malloc(sizeof(levelorder_queue_t));
	if (n == NULL)
		return (NULL);

	n->node = node;
	n->next = NULL;

	return (n);
}

/**
 * pint_push - A function that runs a function on a given binary tree node and pushes its children into
 * a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node
 * Description: If malloc fails exit with 1
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * free_queue - A function that frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pop - A function that pops the head of a levelorder_queue_t queue
 * @head: A double pointer to the head of the queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
