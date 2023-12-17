#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	line_number = line_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints each character of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
		return;
	while (*stack != NULL)
	{
		printf("%c\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
