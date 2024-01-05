#include "monty.h"

/**
* line_scanner - Scan each line of file and execute find_function for command.
*
* @file: pointer to the file to be scanned.
* Return: Always 0, indicating the completion of line scanning.
*/
int line_scanner(FILE **file)
{
	char *line = NULL;
	char *token = NULL;
	size_t len = 0;
	char *command = NULL;
	stack_t *arrayStack = NULL;

	while (getline(&line, &len, *file) > 0)
	{
		command = strtok(line, " \t\n\r");
		len++;

		if (!command)
			continue;

		token = strtok(NULL, " \t\n\r");
		while (token && strlen(token) == 0)
			token = strtok(NULL, " \t\n\r");
		find_function(&arrayStack, command, token);
	}

	return (0);
}

