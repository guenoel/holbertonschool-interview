#include "binary_trees.h"

/* Variable to track memory allocation errors */
static int flag_error;

/**
* restore_max_heap_property - Restores the Max Heap property by swapping values
* upwards
*
* @new_node: Pointer to the new_node node
*/
void restore_max_heap_property(heap_t **new_node)
{
	heap_t *current_node;
	int tmp;

	for (current_node = *new_node; current_node->parent;
		current_node = current_node->parent)
		if (current_node->n > current_node->parent->n)
		{
			tmp = current_node->parent->n;
			current_node->parent->n = current_node->n;
			current_node->n = tmp;
			*new_node = (*new_node)->parent;
		}
}

/**
* delete_n_queue - Deletes a node from the queue.
*
* @node_queue: Double pointer to the node in the queue
*/
void delete_n_queue(tree_queue **node_queue)
{
	tree_queue *tmp;

	if (*node_queue)
	{
		tmp = *node_queue;
		*node_queue = (*node_queue)->next;
		free(tmp);
	}
}

/**
* enqueue - Adds the address of 'current_node' to the queue.
*
* @node_queue: Double pointer to the node in the queue
* @current_node: Pointer to the current node
*
* Return: Pointer to the newly created queue node
*/
tree_queue *enqueue(tree_queue **node_queue, heap_t *current_node)
{
	tree_queue **current_q;
	tree_queue *new_node_q = (tree_queue *)malloc(sizeof(*new_node_q));

	if (!new_node_q)
		return (NULL);
	new_node_q->node = current_node;
	new_node_q->next = NULL;

	current_q = node_queue;
	while (*current_q)
		current_q = &(*current_q)->next;
	new_node_q->next = *current_q;
	*current_q = new_node_q;
	return (new_node_q);
}


/**
* push_insert - Adds a node to the queue and inserts it into the binary tree.
*
* @current_node: Pointer to the current node
* @node_queue: Double pointer to the current queue node
* @new_node: Double pointer to the new_node node
* @direction: Double pointer to the current direction
* @value: Value stored in the node to insert
*
* Return: Pointer to the new_node node
*/
heap_t *push_insert(heap_t *current_node, tree_queue **node_queue,
					heap_t **new_node, heap_t **direction, int value)
{
	if (*direction)
	{
		if (!enqueue(node_queue, *direction))
			flag_error = 1;
	}
	else
	{
		*direction = binary_tree_node(current_node, value);
		if (!*direction)
			flag_error = 1;
		*new_node = *direction;
	}
	return (*new_node);
}

/**
* order - Traverses the tree in level order.
*
* @root: Double pointer to the root node
* @value: Value stored in the node to insert
*
* Return: Pointer to the new_node node, or NULL on failure
*/
heap_t *order(heap_t **root, int value)
{
	tree_queue *current_q = NULL;
	heap_t *new_node, *current_node = *root;

	if (!enqueue(&current_q, current_node))
		return (NULL);
	new_node = NULL;
	while (current_q)
	{
		current_node = current_q->node;
		if (!new_node)
			push_insert(current_node, &current_q,
					&new_node, &current_node->left, value);
		if (!new_node)
			push_insert(current_node, &current_q,
					&new_node, &current_node->right, value);
		if (flag_error)
			return (NULL);
		delete_n_queue(&current_q);
	}
	return (new_node);
}

/**
* heap_insert - Inserts a value into a maximum binary heap.
*
* @root: Double pointer to the root node of the heap
* @value: Value stored in the node to insert
*
* Return: Pointer to the added node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		new_node = *root;
	}
	else
	{
		new_node = order(root, value);
		restore_max_heap_property(&new_node);
	}
	return (new_node);
}
