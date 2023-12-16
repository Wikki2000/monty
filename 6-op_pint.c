#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack, followed by a new line.
 * @stack: 
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	line_number = 1;

	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
