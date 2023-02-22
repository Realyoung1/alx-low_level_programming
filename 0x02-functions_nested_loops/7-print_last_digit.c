#include "main.h"

/**
 * print_last_digit - print last digit
 * @n: the number
 * Return: The value of the last digit
 */
int print_last_digit(int n)

{
	int ld = n % 10;

	if (ld < 0)
		ld *= -1;

	_putchar(ld + '0');

	return (0);
}
