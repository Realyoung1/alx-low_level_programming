#include "main.h"
/**
 * puts_half - function that prints half of a string, followed by a new line
 * @str: char to check
 * Owned by RealDevices Tech/Realyoun1
 * Return: 0 is success
 */
void puts_half(char *str)
{
	int string = 0, n;

	while (str[string] != '\0')
		string++;
	if (string + 1 % 2 != '0')
		n = (string - 1) / 2;
	else
		n = (string / 2);
	n++;

	for (string = n; str[string] != '\0'; string++)
	_putchar(str[string]);
	_putchar('\n');
}
