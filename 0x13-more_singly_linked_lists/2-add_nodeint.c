#include "lists.h"

/**
 * add_nodeint - this adds a new node at thebeginning of a linked list
 * @head: this points to the first node in the list
 * @n: this is data to insert a new node
 *
 * Return: the pointer to the new node, or NULL if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
