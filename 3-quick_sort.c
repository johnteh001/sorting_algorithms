#include "sort.h"
/**
 * quick_sort - algorithm sorts in ascending order using quicksort
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quicksort(array, 0, (int)size - 1, (int)size);
}
/**
 * quicksort - Function obtains parameters for quick sorting
 * @array: array to be sorted
 * @beg: beginning index
 * @end: ending index
 * @size: array size
 */
void quicksort(int *array, int beg, int end, int size)
{
	int p_index;

	if (beg < end)
	{
		p_index = partioner(array, beg, end, size);
		quicksort(array, beg, p_index - 1, size);
		quicksort(array, p_index + 1, end, size);
	}
}
/**
 * partioner - functoin finds the array partioning index
 * @array: array to be partioned
 * @beg: begging index
 * @end: ending index
 * @size: array size
 *
 * Return: index where the array is partioned
 */
int partioner(int *array, int beg, int end, int size)
{
	int pivot;
	int i, j;

	i = (beg - 1);
	pivot = array[end];
	for (j = beg; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, (size_t)size);
		}
	}
	swap(&array[i + 1], &array[end]);
	if (array[i + 1] != array[end])
		print_array(array, (size_t)size);
	return (i + 1);
}
/**
 * swap - Function swaps array elements
 * @i: first argument
 * @j: second argument
 *
 * Return: 1 on success
 */
int swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
	return (1);
}
