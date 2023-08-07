#include "main.h"
/**
 * main - C program that copied file content from one to another
 * @argc: size of array argv and number of command line arguments
 * @av: An  array  of size argc
 * Return: Always successful
 */
int main(int argc, char *av[])
{
	int fileone, filetwo, fileread, filewrite;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fileone = open(av[1], O_RDONLY);
	if (fileone == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	filetwo  = open(av[2], O_TRUNC | O_CREAT | O_WRONLY, 0664);
	if (filetwo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}
	do  {
		fileread = read(fileone, buffer, 1024);
		if (fileread ==  -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			exit(98);
		}
		filewrite = write(filetwo, buffer, fileread);
		if (filewrite == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	} while (fileread == 1024);

	if (close(fileone) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileone);
		exit(100);
	}
	if (close(filetwo) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filetwo);
		exit(100);
	}
	return (0);
}
