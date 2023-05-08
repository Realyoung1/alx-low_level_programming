#include "main.h"

/**
 * read_textfile - Writting the function that reads a text file and
 * prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int gh;
	ssize_t lenk, lenz;
	char *buffer;

	if (filename == NULL)
		return (0);
	gh = open(filename, O_RDONLY);
	if (gh == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(gh);
		return (0);
	}
	lenk = read(gh, buffer, letters);
	close(gh);
	if (lenk == -1)
	{
		free(buffer);
		return (0);
	}
	lenz = write(STDOUT_FILENO, buffer, lenk);
	free(buffer);
	if (lenk != lenz)
		return (0);

	return (lenz);
}
