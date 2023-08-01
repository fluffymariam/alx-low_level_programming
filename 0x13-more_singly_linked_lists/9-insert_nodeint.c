#include "lists.h"

/**
 * insert_nodeint_at_index - this will insert a new node n a linked list
 *
 * @head: this is the pointer to the first node in the list
 * @idx: this is where the new node will be added
 * @n: this is the data to insert in the new node
 * Return: the new node pointer
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int m;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	m = 0;

	while (temp && m < idx)
	{
		if (m == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return new;
		}

		temp = temp->next;
		m++;
	}

	return (NULL);
}
