#include "main.h"

/**
 * print_alphabet_x10 - Entry point to make alphabet x10 times
 * Return: Always 0 (Success)
 */

void print_alphabet_x10(void)

{
	char c;
	int i = 0;

	while (i <= 9)
	{
	for (c = 'a'; c <= 'z'; c++)
	{
	_putchar(c);

	_putchar('\n');
	i++;
	}
	}
}
