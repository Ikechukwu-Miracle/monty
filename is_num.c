#include "monty.h"

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
