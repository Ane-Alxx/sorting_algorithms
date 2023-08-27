#include "sort.h"
/**
* bubble_sort - function for bubble sorting
* @array: the array to be sorted
* @size: length of our array
*/
void bubble_sort(int *array, size_t size)
{

	size_t lenny, point, cont = 0;

	if (size < 2)
		return;
	for (lenny = 0; lenny < size; lenny++)
		for (point = 0; point < size; point++)
		{
			if (array[point] > array[point + 1] && array[point + 1])
			{
			cont = array[point];
			array[point] = array[point + 1];
			array[point + 1] = cont;
			print_array(array, size);
			}
		}
}
