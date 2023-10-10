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

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
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
