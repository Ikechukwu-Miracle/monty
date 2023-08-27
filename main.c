#include "monty.h"
#include <stdio.h>

flag_sq = 0;

/**
 * main - entry point of monty code interpreter
 * @argc: argument count
 * @argv: vector of arguments passed to program
 *
 * Return: on success 0
 */
int main(int argc, char *argv[])
{
	char *op_code, *buff = NULL;
	int line_num = 1;
	size_t n = 0;
	FILE *file;
	stack_t *sk = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		stack_free(sk);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &n, file) != -1)
	{
		op_code = strtok(buff, " \t\n");
		if (op_code == NULL || op_code[0] == '#')
		{
			line_num++;
			continue;
		}
		pre_exec(op_code, &sk, line_num);
		line_num++;
	}

	fclose(file);
	free(buff);
	stack_free(sk);
	return (0);
}
