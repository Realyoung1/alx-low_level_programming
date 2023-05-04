#include "main.h"
/**
 * get_endianness - I am writing a function that checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int d;
	char *c;

	d = 1;
	c = (char *)&d;

	return (*c);
}
