#include "binary_trees.h"

/**
 * heapify - heapifies an array
 * @array: array to heapify
 * @orig_size: original size of array
 * @size: size of array
 * @i: index to heapify
 */
void heapify(heap_t **array, size_t orig_size, size_t size, size_t i)
{
	size_t largest, left = 2 * i + 1, right = 2 * i + 2;
	int tmp;

	/* if no children */
	if (left >= size && right >= size)
		return;

	/* if 2 children */
	if (left < size && right < size)
		largest = (array[left]->n > array[right]->n) ? left : right;
	else /* if only one child */
		largest = (right < size) ? right : left;

	/* swap parent and child if needed and repeat for descendants */
	if (array[largest]->n > array[i]->n)
	{
		tmp = array[i]->n;
		array[i]->n = array[largest]->n;
		array[largest]->n = tmp;

		for (size_t j = 0; j < (orig_size - 1); j++)
		{
			if (array[j])
				printf("%d, ", array[j]->n);
			else
				printf("NULL, ");
		}
		printf("\n");
		heapify(array, orig_size, size, largest);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *node = NULL, *tmp = NULL;
	int value = 0, depth = 0, i = 0, heap_size = 0;
	heap_t **max_queue = NULL;

	if (!root || !*root)
		return (0);

	node = *root; /* save root node to free it later */
	value = node->n; /* save value to return later */
	/* find depth of the tree */
	for (depth = 1, tmp = *root; tmp->left; tmp = tmp->left)
		depth++;

	(*root)->n = node->n;
	heap_size = (1 << depth) - 1;
	max_queue = malloc(sizeof(heap_t *) * heap_size);
	if (!max_queue)
		return (0);
	max_queue[0] = *root;
	for (i = 0; max_queue[i] && i < heap_size; i++)
	{
		if (max_queue[i]->left && ((i * 2) + 1) <= (heap_size - 1))
		{
			max_queue[(i * 2) + 1] = max_queue[i]->left;
			/* printf("%d ", max_queue[(i * 2) + 1]->n); */
		}
		if (max_queue[i]->right && ((i * 2) + 2) <= (heap_size - 1))
		{
			max_queue[(i * 2) + 2] = max_queue[i]->right;
			/* printf("%d ", max_queue[(i * 2) + 2]->n); */
		}
	}
	printf("\n");

	/* for (j = 0; j < (heap_size - 1); j++)
	{
		if (max_queue[j])
			printf("%d, ", max_queue[j]->n);
		else
			printf("NULL, ");
	} */
	/* printf("\n"); */
	/* printf("max_queue[%d] = %d\n", i - 1, max_queue[i - 1]->n); */

	printf("i - 1: %d = %d\n", i - 1, max_queue[i - 1]->n);
	if (max_queue[i - 1]->parent->right == max_queue[i - 1])
		max_queue[i - 1]->parent->right = NULL;
	else if (max_queue[i - 1]->parent->left == max_queue[i - 1])
		max_queue[i - 1]->parent->left = NULL;
	max_queue[i - 1]->parent = NULL;

	*root = max_queue[i - 1];
	(*root)->left = node->left;
	(*root)->right = node->right;

	heapify(max_queue, heap_size, heap_size, 0);

	free(max_queue);
	return (value);
}
