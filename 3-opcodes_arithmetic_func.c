#include "monty.h"
/**
 * op_add - Adds the top two elements of the stack
 * @stack: The stack to operate on
 * @line_number: Line number in the Monty bytecode file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	line_number = line_value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add to the second node so the top can be pop out */
	(*stack)->next->n += (*stack)->n;
	op_pop(stack, 0);
}

/**
 * op_sub - substract the top two elements of the stack
 * @stack: The stack to operate on
 * @line_number: Line number in the Monty bytecode file
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
        line_number = line_value;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        /* Add to the second node so the top can be pop out */
        (*stack)->next->n -= (*stack)->n;
        op_pop(stack, 0);
}
