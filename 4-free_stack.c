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
