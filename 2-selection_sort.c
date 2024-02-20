#include "sort.h"
/**
 * swap - Swaps the values of two integers.
 * @ptr1: Pointer to the first integer.
 * @ptr2: Pointer to the second integer.
 */
void swap(int *ptr1, int *ptr2)
{
	int temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[i] != array[min])
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}

