#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * read_textfile - Read and prints a text file to POSIX standard output
 * @filename: the name of the file
 * @letters: The numbeer of letters to read and print
 * Return: The number of letters to be printed and 0 if error
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytes_read = 0;
	char *mariam;
	FILE *lad;

	if (filename == NULL)
	{
		return (0);
	}

	mariam = malloc(letters);
	if (mariam == NULL)
	{
		return (0);
	}

	lad = fopen(filename, "r");
	if (lad == NULL)
	{
		free(mariam);
		return (0);
	}
	bytes_read = fread(mariam, sizeof(char), letters, lad);
	if (bytes_read <= 0)
	{
		fclose(lad);
		free(mariam);
		return (0);
	}
	bytes_read = write(STDOUT_FILENO, mariam, bytes_read);
	if (bytes_read < 0)
	{
		fclose(lad);
		free(mariam);
		return (0);
	}

	fclose(lad);
	free(mariam);
	return (bytes_read);
}
