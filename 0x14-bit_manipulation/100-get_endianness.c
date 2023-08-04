#include "main.h"

/**
 * get_endianness - checks if little or big
 * Return: 0 for big 1 for small
 *
 */

int get_endianness(void)
{
	unsigned int m = 1;

	char *c = (char *) &m;

	return (*c);
}
