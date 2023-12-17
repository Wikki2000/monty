#include "monty.h"

/**
 * op_push - Pushes an element onto the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * op_pall - Prints all values on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        (void)line_number;

        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}

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
