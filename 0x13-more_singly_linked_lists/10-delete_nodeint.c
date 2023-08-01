#include "lists.h"

/**
 *  delete_nodeint_at_index - this delete node in linked list
 *  @head: this will point at the fisrt element
 *  @index: this will point to the node to be deleted
 *
 *  Return: 1 if successful or -1 if fail
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int m = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (m < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		m++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
