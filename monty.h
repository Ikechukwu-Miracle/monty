#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


extern int flag_sq;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_func)(stack_t **stack, unsigned int line_number);

void _pop(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void pre_exec(char *line, stack_t **stack, int line_num);
op_func get_opcode(char *str);
void stack_free(stack_t *head);
stack_t *push_stack(stack_t **head, int n);
int is_num(char *str);
void _push(stack_t **head, unsigned int line_num);
void _pall(stack_t **head, unsigned int line_num);
void _swap(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);

#endif
