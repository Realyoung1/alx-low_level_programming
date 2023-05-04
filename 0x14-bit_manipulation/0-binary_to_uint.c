#include "main.h"

/**
 * binary_to_uint -This is to write a function that converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int d;
	unsigned int v;

	v = 0;
	if (!b)
		return (0);
	for (d = 0; b[d] != '\0'; d++)
	{
		if (b[d] != '0' && b[d] != '1')
			return (0);
	}
	for (d = 0; b[d] != '\0'; d++)
	{
		v <<= 1;
		if (b[d] == '1')
			v += 1;
	}
	return (v);
}
