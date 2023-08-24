#include "monty.h"

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
		exit(EXIT_FAILURE);
	}
	push_stack(stack, num_arg);
}

#include "monty.h"

/**
 * add_dnodeint - adds node at the beginning of doubly
 * linked list
 * @head: points to the pointer of first element of the list
 * @n: integer value of the new node
 *
 * Return: pointer to the newNode
 */
stack_t *push_stack(stack_t **head, int n)
{
	stack_t *newNode, *temp = *head;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->prev = NULL;

	if (*head == NULL)
		*head = newNode;
	else
	{
		newNode->next = temp;
		temp->prev = newNode;
		*head = newNode;
	}

	return (newNode);
}
