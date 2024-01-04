#include "monty.h"

int line_scanner(FILE **file)
{
	char *line = NULL;
	char *token = NULL;
	size_t len = 0;
	char *command = NULL;

	while (getline(&Line, &len, file) > 0)
	{
		command = strtok(line, " \t\n\r");
		l++;

		if (!command)
			continue;

		token = strtok(NULL, " \t\n\r");
		while (token && strlen(token) == 0)
			token = strtok(NULL, " \t\n\r");
	}
	return (0);
}
