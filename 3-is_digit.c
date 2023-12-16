#include "monty.h"

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
