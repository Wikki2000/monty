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
    unsigned int line_number = 0;
    char buffer[MAX_SIZE];
    stack_t *my_stack = NULL;
    char *token[3];

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(av[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s", av[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        token[0] = strtok(buffer, " \n");
        if (token[0] == NULL)
        {
            fprintf(stderr, "Error: Missing opcode on line %u\n", line_number);
            exit(EXIT_FAILURE);
        }
        token[0][strcspn(token[0], "\n")] = '\0';
        token[1] = strtok(NULL, " \n");

        if (token[1] == NULL)
		token[1] = "0";
        get_opcode(token[0])(&my_stack, atoi(token[1]));
        line_number++;
    }

    fclose(file);
    return (0);
}

