#include "sort.h"

/**
 *selection_sort - sort using selection algorithm
 *@array: array
 *@size: array size
 */

void selection_sort(int *array, size_t size)
{
	size_t pos = 0, j = 0, x;
	int minor;

	if (size < 2)
		return;
	for (pos = 0; pos < size - 1; pos++)
	{
		minor = array[pos];
		x = pos;
		for (j = pos + 1; j < size; j++)
		{
			if (minor > array[j])
			{
				minor = array[j];
				x = j;
			}
		}
		array[x] = array[pos];
		array[pos] = minor;
		if (pos != x)
		{
			print_array(array, size);
		}
	}
}
