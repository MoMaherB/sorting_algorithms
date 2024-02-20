#include "sort.h"
/**
 * partison - Chooses a pivot and partitions the array into two halves.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @l: The low index of the partition.
 * @h: The high index of the partition.
 * Return: The index of the pivot.
 */
int partison(int *array, size_t size, int l, int h)
{
	int start = l, end = h;
	int pivot = array[end], temp;

	while (start < end)
	{
		while (array[start] < pivot)
			start++;
		while (array[end] >= pivot)
			end--;
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}
	}
	if (array[start] > pivot)
	{
		temp = array[start];
		array[start] = array[h];
		array[h] = temp;
		print_array(array, size);
	}

	return (start);

}

/**
 * quick_sort_recursion - Implements the recursive QuickSort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @l: The low index of the partition.
 * @h: The high index of the partition.
 */
void quick_sort_recursion(int *array, size_t size, int l, int h)
{
	int loc;

	if (l < h)
	{
		loc = partison(array, size, l, h);
		quick_sort_recursion(array, size, l, loc - 1);
		quick_sort_recursion(array, size, loc + 1, h);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using QuickSort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, (int)size - 1);
}
