#include "monty.h"

/**
 * is_num - checks if a string is an integer number
 * @str: pointer to string
 *
 * Return: 1 if it is a number and 0 otherwise
 */
int is_num(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}

		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
