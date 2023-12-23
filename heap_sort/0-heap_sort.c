#include "sort.h"

/* https://www.youtube.com/watch?v=HqPJF2L5h9U&ab_channel=AbdulBari */

/**
 * heapify - heapifies an array
 * @array: array to heapify
 * @orig_size: original size of array
 * @size: size of array
 * @i: index to heapify
 */
void heapify(int *array, size_t orig_size, size_t size, size_t i)
{
	size_t largest, left = 2 * i + 1, right = 2 * i + 2;
	int tmp;

	/* if no children */
	if (left >= size && right >= size)
		return;

	/* if 2 children */
	if (left < size && right < size)
		largest = (array[left] > array[right]) ? left : right;
	else /* if only one child */
		largest = (right < size) ? right : left;

	/* swap parent and child if needed and repeat for descendants */
	if (array[largest] > array[i])
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, orig_size);
		heapify(array, orig_size, size, largest);
	}
}

/**
 * heap_delete - deletes the root node of a heap
 * @array: array to delete from
 * @orig_size: original size of array
 * @size: size of array
 */
void heap_delete(int *array, size_t orig_size, size_t size)
{
	int tmp;

	/* swap root node with last node */
	tmp = array[0];
	array[0] = array[size - 1];
	array[size - 1] = tmp;
	/* repeat until size == 1 */
	if (size > 1)
	{
		print_array(array, orig_size);
		heapify(array, orig_size, size - 1, 0);
		heap_delete(array, orig_size, size - 1);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t pow2;
	int height = 0;
	int i;

	if (!array || size < 2)
		return;

	/* Calculate size of the array/tree */
	for (pow2 = 1; (pow2 - 1) < size; pow2 *= 2)
		height++;

	/* heapify array/tree except leaves */
	for (i = pow2 / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	/* delete==sort root node until tree is empty */
	heap_delete(array, size, size);
}
