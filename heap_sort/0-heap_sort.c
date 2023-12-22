#include "sort.h"

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

	if (left > (size - 1) && right > (size - 1))
		return;

	if (left < (size - 1) && right < (size - 1))
		if (array[left] > array[right])
			largest = left;
		else
			largest = right;
	else
		largest = array[left] ? left : right;

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

	if (size == 1)
	return;

	tmp = array[0];
	array[0] = array[size - 1];
	array[size - 1] = tmp;
	print_array(array, orig_size);
	heapify(array, orig_size, size - 1, 0);
	heap_delete(array, orig_size, size - 1);
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

	for (pow2 = 1; (pow2 - 1) < size; pow2 *= 2)
		height++;

	for (i = pow2 / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	heap_delete(array, size, size);
}
