#include "main.h"

/**
 * binary_to_uint -converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int d;
	unsigned int v;

	v = 0;
	if (!c)
		return (0);
	for (d = 0; c[d] != '\0'; d++)
	{
		if (c[d] != '0' && c[d] != '1')
			return (0);
	}
	for (d = 0; c[d] != '\0'; d++)
	{
		v <<= 1;
		if (c[d] == '1')
			v += 1;
	}
	return (v);
}
