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
  * interpolation_search - searched the firsted ocurrency of a valued in the.
  * @array: setted of numbered
  * @size: sized of the arrays
  * @value: valued to searches
  * Return: returned the first index located otherwise -1
  */

int interpolation_search(int *array, size_t size, int value)
{
	size_t l = 0, r = size - 1, pos = 0;

	if (array == NULL)
		return (-1);
	pos = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
	if (pos >= size)
		printf("Value checked array[%d] is out of range\n", (int) pos);
	while ((array[r] != array[l]) && (value >= array[l]) && (value <= array[r]))
	{
		pos = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
		printf("Value checked array[%d] = [%d]\n", (int) pos, array[pos]);

		if (array[pos] < value)
			l = pos + 1;
		else if (array[pos] > value)
			r = pos - 1;
		else
			return (pos);
	}
	if (array[l] == value)
		return (l);
	return (-1);
}
