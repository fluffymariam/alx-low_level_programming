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

/**
 * print_listint_safe - will print in a safe form
 * @head:points to the first node
 * Return: the num to be printed
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t a, b = 0;
		a = looped_listint_len(head);
	if (a == 0)
	{
		for (; head != NULL; a++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (b = 0; b < a; b++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("->[%p]%d\n", (void *)head, head->n);
	}
	return (a);
}
