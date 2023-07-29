#include "sort.h"

/**
 * l_partition - lomuto partition function that helps
 * with the quick sort function
 * @array: array to sort
 * @low: start of the partition to sort
 * @high: end of the partition to sort
 * Return: index i
 */
size_t l_partition(int *array, size_t low, size_t high)
{
	size_t i = low - 1, j;
	int piv = array[high], temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, high + 1);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	print_array(array, high + 1);
	return (i);
}


/**
 * quick_recursive - function that helps the quick sort function
 * through recursion
 * @array: array to sort
 * @low: start of the partition to sort
 * @high: end of the partition to sort
 * Return: nothing
 */
void quick_recursive(int *array, size_t low, size_t high)
{
	size_t piv = 0;
	if (low < high)
	{
		piv = l_partition(array, low, high);
		if (piv > 0)
			quick_recursive(array, low, piv - 1);
		quick_recursive(array, piv + 1, high);
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
	quick_recursive(array, 0, size - 1);
}
