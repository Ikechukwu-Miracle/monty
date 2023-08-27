#include "monty.h"

/**
 * get_opcode - gets the operation code to work on
 * @str: string to check for operation code
 * Return: returns the function to execute the op_code
 */

op_func get_opcode(char *str)
{
	int x = 0;

	instruction_t op_code[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};
	while (op_code[x].f != NULL && strcmp(op_code[x].opcode, str) != 0)
		x++;
	return (op_code[x].f);
}

/**
 * _stack - sets the program to stack
 * @stack: pointer to stack list
 * @line_num: line number
 * Return: nothing
 */
void _stack(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_num)
{
	flag_sq = 0;
}

/**
 * _queue - sets program to queue
 * @stack: pointer to stack list
 * @line_num: line number
 * Return: nothing
 */
void _queue(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_num)
{
	flag_sq = 1;
}
