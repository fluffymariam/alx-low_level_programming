#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - will count the number of notes
 *
 * @head: this will point to the head
 *
 * Return: 0 iflist is looped
 * Otherwise - the nodes in liat
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tom, *jerry;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tom = head->next;
	jerry = (head->next)->next;

	while (jerry)
	{
		if (tom == jerry)
		{
			tom = head;
			while (tom != jerry)
			{
				nodes++;
				tom = tom->next;
				jerry = jerry->next;
			}

			tom = tom->next;
			while (tom != jerry)
			{
				nodes++;
				tom = tom->next;
			}
			return (nodes);
		}
		tom = tom->next;
		jerry = (jerry->next)->next;
	}
	return (0);
}
