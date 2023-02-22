#include <stdio.h>
/**
 * main - first 98 Fibonacci numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int i, a = 0, b = 1, c;

	for (i = 0; i < 98; i++)
	{
		c = a + b;
		a = b;
		b = c;
		if (i < 97)
		{
			printf("%li, ", c);
		}
		else
		{
			printf("%li\n", c);
		}
	}
	return (0);
}
