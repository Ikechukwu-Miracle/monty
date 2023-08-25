#include "monty.h"

/**
 * _push - adds (pushes) a new element to the stack
 * @stack: pointer to the stack list
 * @line_num: line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_num)
{
	char *arg;
	int num_arg = 0;
	
	arg = strtok(NULL, " \t\n");
	
	if (arg != NULL && is_num(arg) == 1)
		num_arg = atoi(arg);
	else
	{
		fprintf(stderr, "L%d: usage push integer\n", line_num);
		stack_free(*stack);
		*stack = NULL;
		exit(EXIT_FAILURE);
	}
	push_stack(stack, num_arg);
}

/**
 * push_stack - adds node at the beginning of doubly
 * linked list
 * @stack: points to the pointer of first element of the list
 * @n: integer value of the new node
 *
 * Return: pointer to the newNode
 */
stack_t *push_stack(stack_t **head, int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return NULL;

	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head != NULL)
		(*head)->prev = newNode;

	*head = newNode;

	return newNode;
}

/**
 * _pint - prints the data at the top stack
 * @stack: double pointer to the data
 * @line_num: line number in file
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the data at the top stack
 * @stack: double pointer to the data
 * @line_num: line number in file
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	temp = NULL;
}

void _div(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	_pop(stack, line_num);
}
