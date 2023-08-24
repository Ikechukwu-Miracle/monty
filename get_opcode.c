#include "monty.h"

op_func get_opcode(char *str)
{
	int x;

	instruction_t op_code[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};

	x = 0;
	while (op_code[x].f != NULL && strcmp(op_code[x].opcode, str) != 0)
		x++;

	return (op_code[x].f);
}
