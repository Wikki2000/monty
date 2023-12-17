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
	char buffer[MAX_SIZE];       
	stack_t *my_stack = NULL;
	char *token[3];

	line_value = 0; /* Assigning global var for tracking line_number */
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
		line_value++;
		buffer[strcspn(buffer, "\n")] = '\0'; /* rem '\n' from a files as a result of enter key press */
		if (is_empty_line(buffer))
			continue;
		token[0] = strtok(buffer, " \n");
		token[1] = strtok(NULL, " \n");

		/* This condition check if command does not need 2nd arg */
		if (token[1] == NULL)
			token[1] = "0";

                /* Check if the 2nd arg for push opcode is an int */
                if ((!is_digit(token[1]) && token[1] != NULL && strncmp(buffer, "push", 4) == 0)
				|| (token[1] == NULL && strncmp(buffer, "push", 4) == 0))
                {
                        fprintf(stderr, "L%d: usage: push integer\n", line_value);
                        exit(EXIT_FAILURE);
                }
		if (get_opcode(buffer) == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_value, buffer);
			exit(EXIT_FAILURE);
		}
		get_opcode(token[0])(&my_stack, atoi(token[1]));
	}
	fclose(file);
	free_stack(my_stack);
	return (0);
}
