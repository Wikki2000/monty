#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

 void (*get_opcode(char *s))(stack_t **, unsigned int);
void op_push(stack_t **stack, unsigned int value);
void op_pall(stack_t **stack, unsigned int line_number);

void op_push(stack_t **stack, unsigned int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

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

 void (*get_opcode(char *s))(stack_t **, unsigned int)
{
    int i;
    instruction_t ops[] = {
        {"push", op_push},
        {"pall", op_pall},
        {NULL, NULL}
    };

    for (i = 0; ops[i].opcode; i++)
    {
        if (strcmp(ops[i].opcode, s) == 0)
            return ops[i].f;
    }

    fprintf(stderr, "Unknown instruction %s\n", s);
    exit(EXIT_FAILURE);
}

int main()
{
	stack_t *stack = NULL;
	get_opcode("push")(&stack, 1);
	get_opcode("push")(&stack, 2);
	get_opcode("push")(&stack, 3);
	get_opcode("pall")(&stack, 3);
/*	
	op_push(&stack, 3);
	op_push(&stack, 2);
	op_push(&stack, 1);
	op_pall(&stack, 0);
*/
	return 0;
}
