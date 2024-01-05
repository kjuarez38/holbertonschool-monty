#include "monty.h"

/**
* main - Entry point of the Monty interpreter program.
*
* @argc: Number of command-line arguments.
* @argv: Array of command-line argument strings.
* Return: 0 on successful execution, EXIT_FAILURE on failure.
*/
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <file>\n");
		return (EXIT_FAILURE);
	}

	line_scanner(&file);

	fclose(file);
	return (0);
}

