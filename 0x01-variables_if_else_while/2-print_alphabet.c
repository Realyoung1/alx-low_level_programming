#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function to return alphabets
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar("\n");
	return (0);
}
