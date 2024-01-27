#include "sort.h"
/**
 * selection_sort - functon performs sorts arrays in ascending order
 * @array: array to be sorted
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min;
	int temp;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i; /* assume first index contains minimum array value */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j; /* becomes the index of the new minimum */
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
