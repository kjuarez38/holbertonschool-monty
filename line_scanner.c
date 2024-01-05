#include "monty.h"

/*
* line_scanner - Scan each line of the file and execute find_function for each command.
*
* @file: pointer to the file to be scanned.
* Return: Always 0, indicating the completion of line scanning.
*/
int line_scanner(FILE **file, char **line)
{
	char *token = NULL;
	size_t len = 0;
	char *command = NULL;
	stack_t *arrayStack = NULL;
	stack_t *temp = NULL;
	int ff;
	int line_number = 0;


	while (getline(line, &len, *file) > 0)
	{
		command = strtok(*line, " \t\n\r");
		len++;

		if (!command || strlen(command) == 0)
			continue;

		token = strtok(NULL, " \t\n\r");
		while (token && strlen(token) == 0)
			token = strtok(NULL, " \t\n\r");
		

		ff = find_function(&arrayStack, command, token);
		
		line_number++;

		if (ff == 0)
			dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line_number);
		
		free(*line);
        *line = NULL;

	}
	

	while (arrayStack != NULL)
    {
        temp = arrayStack;
        arrayStack = arrayStack->next;
        free(temp);
    }
	

	return (0);
}
