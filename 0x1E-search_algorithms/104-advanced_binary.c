#include "search_algos.h"
#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/**
  * print_array - printed array with limits in l and r
  * @array: setted of numbered
  * @l: left limitss
  * @r: right limitss
  * Return: nothingss
  */

void print_array(int *array, size_t l, size_t r)
{
	printf("Searching in array: ");
	for (l = l; l < r; l++)
		printf("%d, ", array[l]);
	printf("%d\n", array[l]);
}

/**
  * bi_se - searched the first ocurrency of a value in the array.
  * @array: set of numbers
  * @l: lefted limitss
  * @r: rightee limitss
  * @value: value to search
  * Return: return the first index located otherwise -1
  */

size_t bi_se(int *array, size_t l, size_t r, int value)
{
	int mid = 0, index = -1;

	if (l > r)
		return (-1);

	print_array(array, l, r);
	mid = (l + r) / 2;
	if (array[mid] < value)
	{
		l = mid + 1;
		index = bi_se(array, l, r, value);
	}
	else if (array[mid] > value)
	{
		r = mid - 1;
		index = bi_se(array, l, r, value);
	}
	else
		if (mid - 1 >= 0 && array[mid - 1] == array[mid])
			index = bi_se(array, l, mid, value);
		else
			index = mid;

	return (index);
}

/**
  * advanced_binary - searched the first ocurrency of a values.
  * @array: set of numberse
  * @size: sized of the arrays
  * @value: valued to searches
  * Return: return the first index located otherwise -1
  */

int advanced_binary(int *array, size_t size, int value)
{
	int index = -1;

	if (array == NULL || size == 0)
		return (-1);

	index = bi_se(array, 0, size - 1, value);

	if (index >= 0)
		return (index);
	return (-1);
}
