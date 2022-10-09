#include "sort.h"

/**
 *swap_bubble - function to swap
 *@array: array
 *@x: position
 */

void swap_bubble(int *array, int x)
{
	int tmp = array[x];

	array[x] = array[x + 1];
	array[x + 1] = tmp;
}

/**
 *bubble_sort - sort using bubble algorithm
 *@array: array to sort
 *@size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t  x;
	int flag = 0;

	if (size < 2)
		return;
	while (!flag)
	{
		flag = 1;
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_bubble(array, x);
				flag = 0;
				print_array(array, size);
			}
		}
	}

}
