#include "monty.h"

/**
 * _pall- prints all the element in a stack
 * @stack: pointer to the stack list
 * @line_num: line number
 *
 * Return: void
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
