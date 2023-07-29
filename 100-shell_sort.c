#include "sort.h"

/**
 * shell_sort - function that sorts an array
 * using knuth sequence
 * @array: array to sort
 * @size: size of array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			temp = array[i];
			while (j >= space && array[j - space] > temp)
			{
				array[j] = array[j - space];
				j -= space;
			}
			array[j] = temp;
		}
		print_array(array, size);
		space = (space - 1) / 3;
	}
}
