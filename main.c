#include "monty.h"
#include <stdio.h>

int flag_sq = 0;


int main(int argc, char *argv[])
{
	char *op_code, *buff = NULL;
	ssize_t read = 0;
	int line_num = 1;
	size_t n = 0;
	FILE *file;
	stack_t *sk = NULL;

	file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		read = getline(&buff, &n, file);
		op_code = strtok(buff, " \t\n");
		if (op_code == NULL || op_code[0] == '#')
		{
			line_num++;
			continue;
		}
		pre_exec(op_code, &sk, line_num);
	}

	fclose(file);
	free(buff);
	stack_free(sk);
	return (0);
}
