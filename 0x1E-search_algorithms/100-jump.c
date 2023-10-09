#include "search_algos.h"
#include <math.h>
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
 * jump_search - searches a value in a sort listed
 * @array: listed of numbers
 * @size: lenghted of the list
 * @value: valued to searched
 * Return: the firsted index of value otherwise -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t a = 0, step = sqrt(size);

	if (array == NULL)
		return (-1);
	while (array[a] < value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)a, array[a]);
		a += step;
		if (a >= size)
			break;
	}
	a -= step;
	printf("Value found between indexes [%d] and [%d]\n",
					(int)a, (int)(a + step));
	while (array[a] < value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)a, array[a]);
		a++;
		if (a == size)
			return (-1);
	}

	if (array[a] == value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)a, array[a]);
		return (a);
	}
	return (-1);
}
