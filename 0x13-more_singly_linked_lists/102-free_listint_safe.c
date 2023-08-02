#include "lists.h"

/**
 * free_listint_safe - this will free the linked list
 * @h: this points to the first node
 * Retuen: The number of fee elements
 *
 */

size_t free_listint_safe(listint_t **h)
{
	size_t hei = 0;
		int same;
		listint_t *temp;

		if (!h || !*h)
			return (0);

		while (*h)
		{
			 same = *h - (*h)->next;
			 if (same > 0)
			 {
			 temp = (*h)->next;
			 free(*h);
			 *h = temp;
			 hei++;
			 }
			 else
			 {
				 free(*h);
				 *h = NULL;
				 hei++;
				 break;
			 }
		}
		*h = NULL;
		return (hei);
}

