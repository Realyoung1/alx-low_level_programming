#include "main.h"

void check_IO_stat(int stat, int gh, char *filename, char mode);
/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: arguments passed
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int srt, desc, n_read = 1024, wrote, close_srt, close_desc;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	srt = open(argv[1], O_RDONLY);
	check_IO_stat(src, -1, argv[1], 'O');
	desc = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(desc, -1, argv[2], 'W');
	while (n_read == 1024)
	{
		n_read = read(srt, buffer, sizeof(buffer));
		if (n_read == -1)
			check_IO_stat(-1, -1, argv[1], 'O');
		wrote = write(desc, buffer, n_read);
		if (wrote == -1)
			check_IO_stat(-1, -1, argv[2], 'W');
	}
	close_srt = close(srt);
	check_IO_stat(close_srt, src, NULL, 'C');
	close_desc = close(desc);
	check_IO_stat(close_desc, desc, NULL, 'C');
	return (0);
}

/**
 * check_IO_stat - checks if a file can be opened or closed
 * @stat: file descriptor of the file to be opened
 * @filename: name of the file
 * @mode: closing or opening
 * @fd: file descriptor
 *
 * Return: void
 */
void check_IO_stat(int stat, int gh, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close gh %d\n", gh);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
