#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t d;

	for (d = 0; str[d]; d++)
		;
	return (d);
}

/**
 * create_file - creates a file.
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int gh;
	ssize_t len = 0;

	if (filename == NULL)
		return (-1);
	gh = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (gh == -1)
		return (-1);
	if (text_content != NULL)
		len = write(gh, text_content, _strlen(text_content));
	close(gh);
	if (len == -1)
		return (-1);
	return (1);
}
