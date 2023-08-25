#include "monty.h"

/**
 * _swap - swaps the top two elements in a stack
 * @stack: pointer to the stack list
 * @line_num: line number
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	int tmp_val;
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp_val = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp_val;
}
