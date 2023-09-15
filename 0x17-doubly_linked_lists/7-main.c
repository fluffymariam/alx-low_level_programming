#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
    dlistint_t *head = NULL;

    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);

    print_dlistint(head);
    printf("-----------------\n");

    insert_dnodeint_at_index(&head, 5, 4096);

    print_dlistint(head);
    free_dlistint(head);
    head = NULL;

    return (EXIT_SUCCESS);
}
