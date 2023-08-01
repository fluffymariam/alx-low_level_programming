#include "lists.h"

/**
 * pop_listint - this deletes the head node of a linked lists
 * @head: this points to the first element in a linked list 
 *
 * Return: this returns the data inside the elements that was deleted,
 * or 0 if the list turns out to be empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int mar;

	if (!head || !*head)
		return (0);

	mar = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (mar);
}
