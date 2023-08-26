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

/**
 * _add - adds top data to second top data in stack
 * @stack: pointer to the stack list
 * @line_num: line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int i, j, sum = 0;
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	i = temp->n;
	j = temp->next->n;

	sum = (i + j);
	(*stack)->next->n = sum;
	_pop(stack, line_num);
}

/**
 * _nop - does nothing
 * @stack: does nothing
 * @line_num: does nothing
 *
 * Return: void
 */
void _nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_num)
{
	;
}

/**
 * _sub - subtracts top data from second top data in stack
 * @stack: pointer to the stack list
 * @line_num: line number
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	int i, j, sum = 0;
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	i = temp->n;
	j = temp->next->n;

	sum = (j - i);
	(*stack)->next->n = sum;
	_pop(stack, line_num);
}
