#include "sort.h"
/**
 * swap - Swaps the values of two integers.
 * @ptrNum1: Pointer to the first integer.
 * @ptrNum2: Pointer to the second integer.
 */
void swap(int *ptrNum1, int *ptrNum2)
{
	unsigned int Temp;

	Temp = *ptrNum1;
	*ptrNum1 = *ptrNum2;
	*ptrNum2 = Temp;
}
/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
