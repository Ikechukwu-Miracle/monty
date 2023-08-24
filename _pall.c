#include "monty.h"

/*void _pall(stack_t **stack, __attribute__((unused))unsigned int line_num)
*{
*	while (*stack != NULL)
*	{
*		printf("%d\n", (*stack)->n);
*		*stack = (*stack)->next;
*	}
}*/

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
        stack_t *current = *stack;
        
        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}

