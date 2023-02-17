#include <stdio.h>

/**
 * main- print all possible different combinationsof two digit
 *
 * Return: Always 0 (Success)
 *
 */

int main(void)

{
	int one = '0';
	int tens = '0';

	for (tens = '0'; tens <= '9'; tens++)/* print tens digit*/
	{
		for (ones = '0'; ones <= '9'; ones++)/*print ones digit*/
		{
			if (!((ones == tens) || (tens > ones)))/*eliminates repitition*/
			{
				putchar(tens);
				putchar(ones);
				if (!(ones == '9' && tens == '8'))/*add comma and space*/
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
