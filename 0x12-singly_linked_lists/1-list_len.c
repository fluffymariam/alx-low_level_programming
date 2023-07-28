#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @m: pointer to the list_t list
 *
 * Return: number of elements in m
 */
size_t list_len(const list_t *m)
{
	size_t l = 0;

	while (m)
	{
		l++;
		m = m->next;
	}

	return (l);
}
