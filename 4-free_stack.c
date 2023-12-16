#include "monty.h"

/**
 * free_stack - Frees a stack of type listint_t.
 * @head: A pointer to the head of the list.
 *
 * Description: This function recursively frees each node and the memory it
 * occupies, starting from the last (tail) node to the first (head) node.
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;

	free_stack(stack->next);
	free(stack);
}
