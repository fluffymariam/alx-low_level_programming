#include "main.h"

/**
 * set_bit - this sets the value to 1
 * @n: a pointer to where to find the bit
 * @n: index of the bit starting from zero
 * @index: this is it
 * Return: 1 if worked, missed << worked
 *
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mariam;

	if (index >= sizeof(unsigned long int) * 8)

		return (-1);
	mariam = 1UL << index;
	*n = *n | mariam;
	return (1);
}
