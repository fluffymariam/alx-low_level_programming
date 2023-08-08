#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_exit(const char *message, const char *filename, int code)
{
	dprintf(STDERR_FILENO, message, filename);
	exit(code);
}

int main(int argc, char *argv[])
{
	int file_from, file_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		error_exit("Error: Can't read from file %s\n", argv[1], 98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_to == -1)
	{
		error_exit("Error: Can't write to %s\n", argv[2], 99);
	}

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			error_exit("Error: Can't write to %s\n", argv[2], 99);
		}
	}

	if (bytes_read == -1)
	{
		error_exit("Error while reading from file %s\n", argv[1], 98);
	}

	if (close(file_from) == -1)
	{
		error_exit("Error: Can't close fd %d\n", argv[1], 100);
	}

	if (close(file_to) == -1)
	{
		error_exit("Error: Can't close fd %d\n", argv[2], 100);
	}

	return (0);
}
