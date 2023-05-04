#include "main.h"

/**
 * clear_bit - This is to write a function that sets the value
 * of a bit to 0 at a given index
 * @n: num  of i
 * @index: starting from 0 of the bit you want to set
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int d;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	d = ~(1 << index);
	*n = *n & d;

	return (1);
}
