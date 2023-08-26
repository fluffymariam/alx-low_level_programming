#include "main.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

/**
 * _write - function writes data to a file descriptor.
 * @fd: file descriptor to write to.
 * @str: pointer to the data to be written.
 * @len: length of the data to be written.
 * Return: number of bytes written on success, or -1 on error
 */

ssize_t _write(int fd, const char *str, size_t len)
{
	return (write(fd, str, len));
}

/**
 * _putchar - writes a character to standard output
 * @c: character to be written
 */

void _putchar(char c)
{
	_write(STDOUT_FILENO, &c, 1);
}

/**
 * print_error - prints error to standard error message and exists
 * @message: error to be printed
 */

void print_error(const char *message)
{
	const char *error = "Error\n";

	while (*error)
		_putchar(*error++);
	while (*message)
		_putchar(*message++);
	_putchar('\n');
	_write(STDERR_FILENO, message, strlen(message));
	exit(98);
}

/**
 * print_elf_header_info - prints info from the elf hedase
 * @header: a pointer to elf header struct
 */


void print_elf_header_info(const Elf64_Ehdr *header)
{
	const char *header_str, *magic_str, *class_str, *elf32_str, *elf64_str, *unknown_str;
	int i;
	char hex[3];

	header_str = "ELF Header:\n";
	while (*header_str)
		_putchar(*header_str++);
	magic_str = "  Magic:   ";
	while (*magic_str)
		_putchar(*magic_str++);
	for (i = 0; i < EI_NIDENT; i++)
	{
		sprintf(hex, "%02x", header->e_ident[i]);
		_putchar(' ');
		_putchar(hex[0]);
		_putchar(hex[1]);
	}
	_putchar('\n');

	class_str = "  Class:                             ";
	while (*class_str)
		_putchar(*class_str++);
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			elf32_str = "ELF32\n";
			while (*elf32_str)
				_putchar(*elf32_str++);
			break;
		case ELFCLASS64:
			elf64_str = "ELF64\n";
			while (*elf64_str)
				_putchar(*elf64_str++);
			break;
		default:
			unknown_str = "<unknown>\n";
			while (*unknown_str)
				_putchar(*unknown_str++);
			break;
	}
}

/**
 * main - entry point of the program
 * @argc: number of cmd line arg
 * @argv: array of pointers to cmd line str
 * Return: 0 on success, 98 on eror
 */


int main(int argc, char *argv[])
{
	const char *usage_str = "Usage: elf_header elf_filename\n";
	const char *open_error_str = "Failed to open file\n";
	const char *read_error_str = "Failed to read ELF header\n";
	const char *not_elf_str = "Not an ELF file\n";
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		while (*usage_str)
			_putchar(*usage_str++);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		while (*open_error_str)
			_putchar(*open_error_str++);
		_write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
		_putchar('\n');
		exit(98);
	}
	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read != sizeof(header))
	{
		close(fd);
		while (*read_error_str)
			_putchar(*read_error_str++);
		exit(98);
	}
	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		close(fd);
		while (*not_elf_str)
			_putchar(*not_elf_str++);
		exit(98);
	}
	print_elf_header_info(&header);
	close(fd);
	return (0);
}
