#include "monty.h"

/**
 * line_scanner - Scan line of file and ex find_function for command.
 *
 * @file: pointer to the file to be scanned
 * @line: number of line.
 * Return: Always 0, indicating the completion of line scanning.
 */
int line_scanner(FILE **file, char **line)
{
	char *token = NULL;
	size_t len = 0;
	char *command = NULL;
	stack_t *arrayStack = NULL;
	int ff;
	int line_num = 0;

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
		line_num++;
		free(*line);
		if (ff == 0)
		{
			dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line_num);
			free_stack(arrayStack);
			fclose(*file);
			exit(EXIT_FAILURE);
		}
		if (ff == 2)
		{
			dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", line_num, command);
			free_stack(arrayStack);
			fclose(*file);
			exit(EXIT_FAILURE);
		}
		*line = NULL;
	}
	free_stack(arrayStack);
	return (0);
}


void free_stack(stack_t *arrayStack)
{
	stack_t *temp;
	while (arrayStack != NULL)
	{
		temp = arrayStack;
		arrayStack = arrayStack->next;
		free(temp);
	}
}
