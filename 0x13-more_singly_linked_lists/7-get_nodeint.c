#include "lists.h"

/**
 * get_nodeint_at_index - this will return the node at a certain index in a linked list
 * @head:first node in the linked list
 * @index: index of the node to return
 *
 * Return:pointer to the new node we're looking for
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int m = 0;
	listint_t *temp = head;

	while (temp && m < index)
	{ 
		temp = temp->next;
			m++;
	}
	return (temp ? temp : NULL);
}
