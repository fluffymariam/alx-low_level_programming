#include "lists.h"

/**
 * find_listint_loop - check for the linked list loop
 * @head: linked list
 *
 * Return: The location of the start or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sluggish = head;
	listint_t *quick = head;

	if (!head)
		return (NULL);
	while (sluggish && quick && quick->next)
	{
		quick = quick->next->next;
		sluggish = sluggish->next;
		if (sluggish == quick)
		{
			sluggish = head;
			while (sluggish != quick)
			{
				sluggish = sluggish->next;
				quick = quick->next;
			}
			return (quick);
		}
	}
	return (NULL);
}
