#include "monty.h"

/**
 * stack_free - deallocates a doubly linked list
 * @head: pointer to the linked list
 *
 * Return: void
 */
void stack_free(stack_t *head)
{
	if (head == NULL)
		return;

	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
