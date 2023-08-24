#include "monty.h"

void pre_exec(char *line, stack_t **stack, int line_num)
{
	op_func s;
	
	s = get_opcode(line);
	
	if (s == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line);
		exit(EXIT_FAILURE);
	}
	s(stack, line_num);
	line_num++;
}
