#include "lists.h"

/**
 * reverse_listint - reverses a linked list back
 * @head: points to the initial node in the list
 *
 * Return: the pointer to the initial node
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *back = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = back;
		back = *head;
		*head = next;
	}

	*head = back;

	return (*head);
}
