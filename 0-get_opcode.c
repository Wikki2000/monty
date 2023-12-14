#include "monty.h"

/**
 * get_opcode - Selects the correct function to perform
 * @s: Opcode string
 *
 * Return: Pointer to the function that corresponds to the opcode,
 *         or NULL if the opcode is not found
 */
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
