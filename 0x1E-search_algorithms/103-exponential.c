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
  * print_array - printed arrays with limited in l and r
  * @array: setted of numbered
  * @l: lefted limited
  * @r: righted limited
  * Return: nothings
  */

void print_array(int *array, size_t l, size_t r)
{
	printf("Searching in array: ");
	for (l = l; l < r; l++)
		printf("%d, ", array[l]);
	printf("%d\n", array[l]);
}

/**
  * binary_search_p - searched the first ocurrency of a value in the array
  * @array: set of numbers
  * @l: left limited
  * @r: right limited
  * @value: value to searched
  * Return: return the first index located otherwise -1
  */

int binary_search_p(int *array, size_t l, size_t r, int value)
{
	size_t mid = 0;

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

/**
  * min_value - geted the min value of two numbered
  * @l: number l
  * @r: number r
  * Return: return the minimun value
  */

size_t min_value(size_t l, size_t r)
{
	return ((l < r) ? l : r);
}

/**
  * exponential_search - search the first ocurrency of a value in the array
  * @array: set of numbered
  * @size: size of the arrayss
  * @value: value to searchss
  * Return: return the first index located otherwise -1
  */

int exponential_search(int *array, size_t size, int value)
{
	size_t pow = 1;

	if (array == NULL)
		return (-1);
	while (pow < size && array[pow] < value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)pow, array[pow]);
		pow *= 2;
	}
	printf("Value found between indexes [%d] and [%d]\n",
					(int)(pow / 2), (int)min_value(pow, size - 1));
	return (binary_search_p(array, pow / 2, min_value(pow, size - 1), value));
}
