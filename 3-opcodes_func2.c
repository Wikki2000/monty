#include "monty.h"

/**
 * free_stack - Frees a stack of type stack_t.
 * @stack: The stack data structure.
 *
 * Description: This function recursively frees stack and the memory it
 * occupies, starting from the last (tail) node to the first (head) node.
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;

	free_stack(stack->next);
	free(stack);
}

/**
 * op_pop - Removes the top element from the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecode file where the opcode is called.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;  /* Unused parameter */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line.value);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
