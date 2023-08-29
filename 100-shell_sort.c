#include "sort.h"

/**
*shell_swap - function for shell_swap
*@list: our array to swap elements in
*@m1: swap this
*@m2: with this
*/
void shell_swap(int *list, int m1, int m2)
{

	int cont;

	cont = list[m1];
	list[m1] = list[m2];
	list[m2] = cont;
}

/**
* shell_sort - function for sorting numbers, shell-sort
* @size: length of the array
* @array: our array of numbers
*/
void shell_sort(int *array, size_t size)
{
	size_t mark = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (mark < size / 3)
		mark = 3 * mark + 1;
	while (mark >= 1)
	{
		for (i = mark; i < size; i++)
			for (index = i; index >= mark &&
			 (array[index] < array[index - mark]); index -= mark)
				shell_swap(array, index, index - mark);
		print_array(array, size);
		mark /= 3;
	}
}
