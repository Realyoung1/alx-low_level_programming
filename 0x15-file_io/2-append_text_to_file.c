#include "main.h"

/**
 * _strlen - findng the length of a stringHow to
 * write a function that appends text at the end of a file
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
 * append_text_to_file - appending a text at the end of a file on how to
 * write a a function that appends text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int gh;
	ssize_t len;

	if (filename == NULL)
		return (-1);
	gh = open(filename, O_WRONLY | O_APPEND);
	if (gh == -1)
		return (-1);
	if (text_content != NULL)
		len = write(gh, text_content, _strlen(text_content));
	close(gh);
	if (len == -1)
		return (-1);
	return (1);
}
