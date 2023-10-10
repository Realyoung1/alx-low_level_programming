#include "search_algos.h"

/**
  * linear_search - searches the firstss ocurrencies of a value in the arrayss
  * @array: settted of numbersss
  * @size: sized of the arrayss
  * @value: values to searches
  * Return: returned the first index locates
  */

int linear_search(int *array, size_t size, int value)
{
	size_t q = 0;

	if (array == NULL)
		return (-1);
	for (q = 0; q < size; q++)
	{
		printf("Value checked array[%d] = [%d]\n", (int) q, (int) array[q]);
		if (array[q] == value)
			return (q);
	}
	return (-1);
}
