#include <stdio.h>
#include <string.h>

/**
 * is_empty_line - Checks if a string represents an empty line (contains only whitespace).
 * @s: The input string to be checked.
 *
 * Return: 1 if the string represents an empty line, 0 otherwise.
 */
int is_empty_line(char *s)
{
    while (*s)
    {
        if (*s != ' ' && *s != '\t' && *s != '\n' && *s != '\r')
            return 0;
        s++;
    }
    return 1;
}

int main(void)
{
    FILE *file;
    char buffer[1024];  // Adjust the size accordingly

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // Trim trailing newline characters
//        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if the line represents an empty line
        if (is_empty_line(buffer))
            continue;

        // Process the non-empty line here
        printf("Non-empty line: %s\n", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
