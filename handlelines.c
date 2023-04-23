#include "main.h"
/**
 * error_alert - prints an error message with the prompt
 * @msg: the error message to print
 *
 * Return: none
 */
void error_alert(char *msg)
{
    k_puts(prompt());
    k_puts(msg);
}

/**
 * remove_end_of_line - removes the newline character from a string
 * @line: the string to remove the newline character from
 *
 * Return: the modified string
 */
void remove_null_term_char(char *prog_input)
{
    int b = 0;

    while (prog_input[b] != '\n')
    {
        b++;
    }

    prog_input[b] = '\0';
}

/**
 * read_line - reads a line from stdin
 * @line: a buffer to store the line read from stdin
 *
 * Return: none
 */
void read_line(char *prog_in)
{
    char *line = NULL;
    size_t len = 0;

    ssize_t read = getline(&line, &len, stdin);

    remove_null_term_char(line);

    if (strcmp(line, "exit") == 0 || read == -1 || strcmp(line, "quit") == 0)
    {
        free(line);
        exit(EXIT_SUCCESS);
    }

    strncpy(prog_in, line, MAX_LINE_LENGTH);
    free(line);
}
