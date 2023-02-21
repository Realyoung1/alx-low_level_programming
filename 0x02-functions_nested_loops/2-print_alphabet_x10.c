#include "main.h"

/**
 * print_alphabet_x10 - Entry point to make alphabet x10 times
 * Return: Always 0 (Success)
 */

void print_alphabet_x10(void)

{
	int ten;
	char la;

	for (ten = 0; ten <= 9; ten++)
	{
		for (la = 'a'; la <= 'z'; la++)
			_putchar(la);
		_putchar('\n');
	}
}
