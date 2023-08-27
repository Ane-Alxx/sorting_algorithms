#include "sort.h"
/**
* selection_sort - function for selection sort
* @size: length of our array
* @array: an array of numbs
*/
void selection_sort(int *array, size_t size)
{
	size_t lenny, track;
	int cont, warp, flag = 0;

	if (array == NULL)
		return;
	for (lenny = 0; lenny < size; lenny++)
	{
		cont = lenny;
		flag = 0;
		for (track = lenny + 1; track < size; track++)
		{
			if (array[cont] > array[track])
			{
				cont = track;
				flag += 1;
			}
		}
		warp = array[lenny];
		array[lenny] = array[cont];
		array[cont] = warp;
		if (flag != 0)
			print_array(array, size);
	}
}
