#include "monty.h"

/**initialize_arguments - Initializes a pointer to
 * stack_s structure.
 */
void initialize_arguments()
{
	arguments = malloc(sizeof(instruction_t));
	if (arguments == NULL)
		malloc_failed();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->head = NULL;
	arguments->line_number = 0;
	arguments->stack =1;
}
