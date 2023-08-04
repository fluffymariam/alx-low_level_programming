#include "main.h"

/**
 * flip_bits - counts bits
 * @n: number 
 * @m: second num
 *
 * Retuen: the num of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int l, add = 0;
	unsigned long int presen;
	unsigned long int only = n ^ m;

	for (l = 63; l >= 0; l--)
	{
		presen = only >> l;
		if (presen & 1)
			add++;
	}
	return (add);
}
