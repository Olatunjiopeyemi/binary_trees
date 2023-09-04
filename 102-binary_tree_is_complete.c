#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
void free_queue(levelorder_queue_t *head);

/**
 * binary_tree_is_complete - A function that checks if a binary tree is complete.
 * @tree: The node of the tree to check.
 * Return: 0 if no tree
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}

/**
 * create_node - A function that creates a new levelorder_queue_t node.
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
 * free_queue - A functions that frees a levelorder_queue_t queue.
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
 * push - A function that pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * Description: If malloc fails exits on 1.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *n;

	n = create_node(node);
	if (n == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = n;
	*tail = n;
}

/**
 * pop - A function that pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
