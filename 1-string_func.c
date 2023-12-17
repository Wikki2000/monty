#include "monty.h"

/**
 * is_empty_line - Checks for empty line
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

/**
 * is_digit - Checks if a string contains at least one digit.
 * @s: The input string to be checked.
 *
 * Return: 1 if at least one digit is found, 0 otherwise.
 */
int is_digit(char *s)
{
	int i;

	if (s == NULL || s[0] == '\0')
		return (0);

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-' || s[i] == '+')
			continue;
		if (!isdigit(s[i]))
			return (0);
	}

	return (1);
}
