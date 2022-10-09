#include "sort.h"
#include <math.h>

/**
 *copy - merge sort algorithm
 *@array: int array
 *@dest: destination array
 *@size: array size
 */

void copy(int *array, int *dest, size_t size)
{
	size_t pos = 0;

	for (pos = 0; pos < size; pos++)
	{
		dest[pos] = array[pos];
	}
}

/**
 *lsd_counting - sort int array using LSD Radix sorting algorithm
 *@array: integer array
 *@sorted: integer array
 *@size: array size
 *@exp: exponential
 */

void lsd_counting(int *array, int *sorted, size_t size, size_t exp)
{
	size_t bi;
	int pos = 0;
	int *buck = malloc(sizeof(int) * 10);

	for (pos = 0; pos < 10; pos++)
		buck[pos] = 0;

	for (pos = 0; pos < (int) size; pos++)
	{
		bi = (array[pos] / exp) % 10;
		/* printf("%u, ", bi); */
		/* printf("%u\n", bi); */
		buck[bi] += 1;
	}
	/* printf("\n"); */
	/* print_array(buck, size); */
	for (pos = 1; pos < (int) size; pos++)
		buck[pos] += buck[pos - 1];
	for (pos = size - 1; pos >= 0; pos--)
	{
		bi = (array[pos] / exp) % 10;
		buck[bi] -= 1;
		/* printf("bip: %u p: %d\n", buck[bi], pos); */
		sorted[buck[bi]] = array[pos];
	}
	free(buck);
}


/**
 *radix_sort - sort int array using LSD Radix sorting algorithm
 *@array: integer array
 *@size: array size
 */

void radix_sort(int *array, size_t size)
{
	int *sorted, min = 0, max = 0;
	/* islast = 0; */
	size_t pos = 0, exp = 1;

	if (size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	copy(array, sorted, size);
	min = array[0];
	max = array[0];
	for (pos = 1; pos < size; pos++)
	{
		if (array[pos] < min)
			min = array[pos];
		else if (array[pos] > max)
			max = array[pos];
	}
	exp = 1;
	while ((max - min) / exp >= 1)
	{
		lsd_counting(array, sorted, size, exp);
		print_array(sorted, size);
		exp *= 10;
		copy(sorted, array, size);
	}
	free(sorted);

}
