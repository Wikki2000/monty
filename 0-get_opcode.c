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
	int i, line_number = -1;
	instruction_t ops[] = {
		{"pall", op_pall}, {"push", op_push},
		{"pint", op_pint}, {"pop", op_pop},
		{"swap", op_swap}, {"add", op_add},
		{"sub", op_sub}, {"div", op_div},
		{"nop", op_nop}, {NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		line_number++;
	}
	return (NULL);
}
