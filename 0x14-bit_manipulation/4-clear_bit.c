#include "main.h"

/**
 * clear_bit - set the value to 0
 * @n: pointer to the number
 * @index: index of bit
 * Return: 1 if error or -1 if no error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
