#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

/**
 * main - to generate a key depending on a username for crackme5
 * @argc: numbers of arguments passed.
 * @argv: arguments passed to main.
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int k, g;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	for (k = 0, add = 0; k < len; k++)
		add += argv[1][k];
	p[1] = l[(add ^ 79) & 63];
	for (k = 0, g = 1; k < len; k++)
		g *= argv[1][k];
	p[2] = l[(g ^ 85) & 63];
	for (g = argv[1][0], k = 0; k < len; k++)
		if ((char)g <= argv[1][k])
			g = argv[1][k];
	srand(g ^ 14);
	p[3] = l[rand() & 63];
	for (g = 0, k = 0; k < len; k++)
		g += argv[1][k] * argv[1][k];
	p[4] = l[(g ^ 239) & 63];
	for (g = 0, k = 0; (char)k < argv[1][0]; k++)
		g = rand();
	p[5] = l[(g ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
