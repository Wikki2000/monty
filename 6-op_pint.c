#include "monty.h"

/**
 * op_pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line.value);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

