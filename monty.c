#include "monty.h"

/**
 * main - Entry point of the program
 * @ac: Count of command-line arguments
 * @av: Command line arguments as strings
 *
 * Return: Always success (0)
 */
int main(int ac, char *av[])
{
	FILE *file;
	unsigned int line_number = 1;
	char buffer[MAX_SIZE];
	stack_t *my_stack = NULL;
	char *token = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		token = strtok(buffer, " ");
		get_opcode(token)(&my_stack, line_number);
		line_number++;
	}

	fclose(file);
	return (0);
}
