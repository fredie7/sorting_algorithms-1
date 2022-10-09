#include "sort.h"

/**
  * swap_s - swap two element of a list
  * @array: array
  * @i: index
  * @j: j
  * @size: the array size
  * Return: nothing
  */
void swap_s(int *array, int i, int j, int size)
{
	int copy_num = 0;

	copy_num = array[i];
	array[i] = array[j];
	array[j] = copy_num;
	print_array(array, size);
}

/**
  * lomuto_p - swap two element of a list
  * @array: array
  * @low: index
  * @high: j
  * @size: the array size
  * Return: nothing
  */
int lomuto_p(int *array, int low, int high, int size)
{
	int pivot = 0, i = 0, j = 0;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
				swap_s(array, j, i, size);
			i++;
		}
	}
	if (i != high)
		swap_s(array, i, high, size);
	return (i);
}

/**
  * qs_algo - swap two element of a list
  * @array: array
  * @low: index
  * @high: j
  * @size: the array size
  * Return: nothing
  */
void qs_algo(int *array, int low, int high, int size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = lomuto_p(array, low, high, size);
		qs_algo(array, low, pivot - 1, size);
		qs_algo(array, pivot + 1, high, size);
	}
}

/**
  * quick_sort - Selection sort
  * @array: array
  * @size: size
  * Return: nothing
  */
void quick_sort(int *array, size_t size)
{
	size_t high = 0, low = 0;

	high = size - 1;
	low = 0;
	qs_algo(array, low, high, size);
}
