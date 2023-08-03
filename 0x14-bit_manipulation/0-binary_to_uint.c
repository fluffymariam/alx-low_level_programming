#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converting binary to unsigned int
 * @b: points to 0 & 1 strings
 * Return: Converted number or 0 if invalid
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int mariam = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			mariam = mariam * 2 + (b[i] - '0');
		}
		else
		{
			return (0);
		}
	}
	return (mariam);
}
