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

/**
 * _pchar - prints character corresponding to integer of top element
 * in the stack.
 * @stack: pointer to stack list
 * @line_num: line number
 *
 * Return: nothing
 */
void _pchar(stack_t **stack, unsigned int line_num)
{
	int charVal = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n < 27) || ((*stack)->n >= 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	charVal = (*stack)->n;
	putchar(charVal);
	putchar('\n');
}

/**
 * _pstr - prints all character corresponding to integers of all the elements
 * in the stack.
 * @stack: pointer to the stack list
 * @line_num: line number
 * Return: nothing
 */
void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp = *stack;
	int tmpVal;

	if (*stack == NULL)
		putchar('\n');
	else
	{
		while (temp != NULL)
		{
			tmpVal = temp->n;
			if (tmpVal == 0 || !isprint(tmpVal))
				break;
			putchar(tmpVal);
			temp = temp->next;
		}
		putchar('\n');
	}
}

/**
 * _rotl - rotates the stack to the right
 * @stack: pointer to the stack list
 * @line_num: line number
 * Return: nothing
 */
void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp, *runner;

	temp = runner = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	*stack = (*stack)->next;
	while (runner->next != NULL)
		runner = runner->next;
	runner->next = temp;
	temp->prev = runner;
	temp->next = NULL;
}


/**
 * _rotr - rotates a stack
 * @stack: pointer to the stack list
 * @line_num: line number
 *
 * Return: void
 */
void _rotr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}

