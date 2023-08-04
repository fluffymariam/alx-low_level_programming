#include "main.h"
#include <unistd.h>

/**
 * _putchar - write the character c to standard output
 * @c: The character to print
 *
 * Return: 1 Success
 * Error, -1 should be returned
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
