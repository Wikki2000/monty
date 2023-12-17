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
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n -= (*stack)->n;
        op_pop(stack, 0);
}

/**
 * op_div - divides the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: The stack to operate on
 * @line_number: Line number in the Monty bytecode file
 */
void op_div(stack_t **stack, unsigned int line_number)
{
        line_number = line_value;


        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	op_pop(stack, 0);
}

/**
 * op_div - modulus of the second top element of the stack
 * and the top element of the stack.
 *
 * @stack: The stack to operate on
 * @line_number: Line number in the Monty bytecode file
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
        line_number = line_value;


        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n %= (*stack)->n;
        op_pop(stack, 0);
}

/**
 * op_mul - multiply the top two elements of the stack
 * @stack: The stack to operate on
 * @line_number: Line number in the Monty bytecode file
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
        line_number = line_value;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n *= (*stack)->n;
        op_pop(stack, 0);
}
