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
  * advanced_binary_recursive - Searches recursively for a value in a sorted
  * @array: A pointer to the first element of the [sub]array to search.
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  * Return: If the value is not present, -1.
  * Description: Prints the [sub]array being searched after each change.
  */

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t q;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (q = left; q < right; q++)
		printf("%d, ", array[q]);
	printf("%d\n", array[q]);

	q = left + (right - left) / 2;
	if (array[q] == value && (q == left || array[q - 1] != value))
		return (q);
	if (array[q] >= value)
		return (advanced_binary_recursive(array, left, q, value));
	return (advanced_binary_recursive(array, q + 1, right, value));
}

/**
  * advanced_binary - Searches for a value in a sorted array
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for
  * Return: If the value is not present or the array is NULL, -1.
  * Description: Prints the [sub]array being searched after each change.
  */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
