

int main(int arg, *char argv[])
{
	FILE *file;
	stack_t *stack;
	array = NULL; 

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1] = "r");
	
	if (file = NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <file>\n");
		return (EXIT_FAILURE)
	}
	

	fclose(file);
	return (0);
}
