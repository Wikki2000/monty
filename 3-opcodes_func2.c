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

	line_number = line_value;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * op_swap - Swaps the top two elements of the stack
 * @stack: The stack to operate on
 * @line_number: Line number in the Monty bytecode file
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	line_number = line_value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
/**
 * op_nop - Does nothing
 * @stack: The stack to operate on
 * @line_number: Line number of monty files
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
