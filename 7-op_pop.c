#include "monty.h"
/**
 * op_pop - Removes the top element from the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file where the opcode is called.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;  /* Unused parameter */

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line.value);
		exit(EXIT_FAILURE);
	}

	/* Create a temporary pointer to the top node */
	temp = *stack;

	/* Update the top pointer to the next node */
	*stack = (*stack)->next;

	/* If there is a new top node, update its prev pointer to NULL */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	/* Free the memory of the removed node */
	free(temp);
}
