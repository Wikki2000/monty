#include "monty.h"

/**
 * is_space - Checks if a string contains at least one space or newline character only.
 * @s: The input string to be checked.
 *
 * Return: 0 if the string contains a space or newline, 1 otherwise.
 */
int is_empty_line(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ')
			return (0);
	}
	return (1);
}
