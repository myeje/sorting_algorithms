#include "sort.h"

/**
 * l_partition - lomuto partition function that helps
 * with the quick sort function
 * @array: array to sort
 * @low: start of the partition to sort
 * @high: end of the partition to sort
 * @size: size of the array
 * Return: index i
 */
size_t l_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low, j;
	int piv = array[high];
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= piv)
		{
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}


/**
 * quick_recursive - function that helps the quick sort function
 * through recursion
 * @array: array to sort
 * @low: start of the partition to sort
 * @high: end of the partition to sort
 * @size: size of array
 * Return: nothing
 */
void quick_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t piv;

	if (low < high)
	{
		piv = l_partition(array, low, high, size);

		if (piv > 0)
			quick_recursive(array, low, piv - 1, size);
		quick_recursive(array, piv + 1, high, size);
	}
}


/**
 * quick_sort - function that sorts an array using
 * the quick sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recursive(array, 0, size - 1, size);
}
