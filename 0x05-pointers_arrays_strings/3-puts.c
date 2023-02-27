#include "main.h"

/**
 * _puts - unction that prints a string, followed by a new line, to stdout
 * @str: the string
 * Owned by RealDevices Tech/Realyoun1
 * Return: the length of the string
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
