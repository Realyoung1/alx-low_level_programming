#include "main.h"
/**
 * flip_bits - Here is to write a function that returns the number
 * of bits you would need to flip to get from one number to another
 * @n: the first number
 * @m: the second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff, result;
	unsigned int v, d;

	v = 0;
	result = 1;
	diff = n ^ m;
	for (d = 0; d < (sizeof(unsigned long int) * 8); d++)
	{
		if (result == (diff & result))
			v++;
		result <<= 1;
	}

	return (v);
}
