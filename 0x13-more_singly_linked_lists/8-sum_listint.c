#include "lists.h"

/**
 *  sum_listint - this function will calculate the sum of the data in the list
 *  @head: this is the first node in the linked list
 *
 *  Return: the total sum
 */

int sum_listint(listint_t *head)
{
	int lad = 0;
	listint_t *temp = head;

	while (temp)
	{
		lad += temp->n;
		temp = temp->next;
	}

	return (lad);
}
