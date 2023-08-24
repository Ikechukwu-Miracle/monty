#include "monty.h"

/**
 * stack_free - frees a doubly linked list
 * @head: pointer to list
 *
 * Return: void
 */
void stack_free(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

