#include "monty.h"

/**
 * _mul - multiplies top data and second top data in stack
 * @stack: data to check
 * @line_num: line number
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_num);
}
