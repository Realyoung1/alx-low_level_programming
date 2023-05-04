#include "main.h"

/**
 * get_bit - I am writiing this function that returns the value
 * of a bit at a given index
 * @n: checking bits
 * @index: which to check bit
 *
 * Return: absolutely (0).
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int fiv, tes;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	fiv = 1 << index;
	tes = n & fiv;
	if (tes == fiv)
		return (1);

	return (0);
}
