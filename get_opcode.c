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
		{NULL, NULL},
	};
	while (op_code[x].f != NULL && strcmp(op_code[x].opcode, str) != 0)
		x++;
	return (op_code[x].f);
}
