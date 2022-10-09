#include "sort.h"
/**
 *selection_sort - sorting by selection algorithm
 *@array:the array
 *@size: th array of the size
 */
void selection_sort(int *array, size_t size)
{
	size_t pos = 0, j = 0, x;
	int minur;

	if (size < 2)
		return;
	for (pos = 0; pos < size - 1; pos++)
	{
		minur = array[pos];
		x = pos;
		for (j = pos + 1; j < size; j++)
		{
			if (minur > array[j])
			{
				minur = array[j];
				x = j;
			}
		}
		array[x] = array[pos];
		array[pos] = minur;
		if (pos != x)
		{
			print_array(array, size);
		}
	}
}
