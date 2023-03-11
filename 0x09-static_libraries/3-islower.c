#include "main.h"

/**
 * _islower- Entry point to check if a character is lowercase
 * @c: the character
 * Return: 1 if c is lowercase, 0 otherwise
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
