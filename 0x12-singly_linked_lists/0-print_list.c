#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints the elements of a linked list
 * @m: pointer to the list_t list to print.
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *m)
{
	size_t l = 0;

	while (m)
	{
		if (!m->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", m->len, m->str);
		m = m->next;
		l++;
	}

	return (l);
}
