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
  * print_array - printed arrays with limits in l and r
  * @array: setted of numbered
  * @l: left limits
  * @r: right limits
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
  * binary_search - searched the first ocurrencies of a valued in the arrays
  * @array: setted of numbered
  * @size: sized of the arrays
  * @value: values to searches
  * Return: return the first index located otherwise -1
  */

int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, r = size - 1, mid = 0;

	if (array == NULL)
		return (-1);
	while (l <= r)
	{
		print_array(array, l, r);
		mid = (l + r) / 2;
		if (array[mid] < value)
			l = mid + 1;
		else if (array[mid] > value)
			r = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
