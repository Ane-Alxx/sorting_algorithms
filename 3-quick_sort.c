#include "sort.h"
/**
*swap - function for swap
*@array: swap in here
*@item1: swap this
*@item2: with this
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int cont;

	cont = array[item1];
	array[item1] = array[item2];
	array[item2] = cont;
}
/**
*list_split - function for list split
*@array: our array
*@head: head array item
*@tail: tail array item
*@size: length of the arrat
*Return: some some
*/
int list_split(int *array, ssize_t head, ssize_t tail, size_t size)
{
	int hinge = array[tail];
	ssize_t active = head, seek;

	for (seek = head; seek < tail; seek++)
	{
		if (array[seek] < hinge)
		{
			if (array[active] != array[seek])
			{
				swap(array, active, seek);
				print_array(array, size);
			}
			active++;
		}
	}
	if (array[active] != array[tail])
	{
		swap(array, active, tail);
		print_array(array, size);
	}
	return (active);
}
/**
*sorter - qucksort algorithm implementation
*@array:our  array
*@head: head of array 
*@tail: tail of array 
*@size: length of our array
*/
void sorter(int *array, ssize_t head, ssize_t tail, int size)
{
	ssize_t mark = 0;


	if (head < tail)
	{
		mark = list_split(array, head, tail, size);

		sorter(array, head, mark - 1, size);
		sorter(array, mark + 1, tail, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sorter(array, 0, size - 1, size);
}
