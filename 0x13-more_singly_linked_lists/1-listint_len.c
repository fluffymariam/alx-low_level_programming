#include "lists.h"

/**
 * listint_len - this will return the number of elements in a linked list
 * @h: the linked list type listint_t to traverse
 *
 * Return: the number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t mar = 0;

	for (; h; h = h->next)
	{
		mar++;
	}

	return (mar);
}
