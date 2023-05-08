#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check67 - checks for the correct number of arguments
 * @argk: number of arguments
 *
 * Return: void
 */
void check67(int argk)
{
	if (argk != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(67);
	}
}

/**
 * check68 - checks that file_from exists and can be read
 * @check: checks if true of false
 * @file: file_from name
 * @ty_from: file descriptor of file_from, or -1
 * @ty_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check68(ssize_t check, char *file, int ty_from, int ty_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (ty_from != -1)
			close(ty_from);
		if (ty_to != -1)
			close(ty_to);
		exit(68);
	}
}

/**
 * check69 - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @file: file_to name
 * @ty_from: file descriptor of file_from, or -1
 * @ty_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check69(ssize_t check, char *file, int ty_from, int ty_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (ty_from != -1)
			close(ty_from);
		if (ty_to != -1)
			close(ty_to);
		exit(69);
	}
}

/**
 * check70 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @ty: file descriptor
 *
 * Return: void
 */
void check70(int check, int ty)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close ty %d\n", ty);
		exit(70);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argk: number of arguments passed
 * @argp: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argk, char *argp[])
{
	int ty_from, ty_to, close_to, close_from;
	ssize_t lenc, lenv;
	char buffer[1024];
	mode_t file_perm;

	check97(argk);
	ty_from = open(argp[1], O_RDONLY);
	check68((ssize_t)ty_from, argp[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	ty_to = open(argp[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check69((ssize_t)ty_to, argp[2], ty_from, -1);
	lenc = 1024;
	while (lenc == 1024)
	{
		lenc = read(ty_from, buffer, 1024);
		check68(lenc, argp[1], ty_from, ty_to);
		lenv = write(ty_to, buffer, lenc);
		if (lenv != lenc)
			lenv = -1;
		check69(lenv, argp[2], ty_from, ty_to);
	}
	close_to = close(ty_to);
	close_from = close(ty_from);
	check70(close_to, ty_to);
	check70(close_from, ty_from);
	return (0);
}
