#include "main.h"
/**
 * exec_child - Executes a child process with the given arguments.
 * @argv: Array of strings containing the command and its arguments.
 */
void exec_child(char **arg_vect)
{
	  if (access(arg_vect[0], X_OK) != 0) {
        fprintf(stderr, "Error: Command '%s' not found\n", arg_vect[0]);
       
    }
    if (execvp(arg_vect[0], arg_vect) < 0)
    {
        fprintf(stderr, "Error: command failed to execute.\n");
        exit(EXIT_FAILURE);
    }
}
/**
 * exec_child_overwrite_from_file - Executes a child process with input redirected from a file.
 * @argv: Array of strings containing the command and its arguments.
 * @dir: Array of strings containing the redirection arguments.
 */
void exec_child_overwrite_from_file(char **arg_vect, char **dest)
{
    int input_fd = open(dest[1], O_RDONLY);
    if (input_fd == -1)
    {
        perror("Error: Redirect input failed");
        exit(EXIT_FAILURE);
    }

    dup2(input_fd, STDIN_FILENO);

    if (close(input_fd) == -1)
    {
        perror("Error: Closing input failed");
        exit(EXIT_FAILURE);
    }

    exec_child(arg_vect);
}
/**
 * exec_child_overwrite_to_file - Executes a child process with output redirected to a file.
 * @argv: Array of strings containing the command and its arguments.
 * @dir: Array of strings containing the redirection arguments.
 */
void exec_child_overwrite_to_file(char **arg_vect, char **dest)
{
    int output_fd = creat(dest[1], S_IRWXU);
    if (output_fd == -1)
    {
        perror("Error: Redirect output failed");
        exit(EXIT_FAILURE);
    }

    dup2(output_fd, STDOUT_FILENO);

    if (close(output_fd) == -1)
    {
        perror("Error: Closing output failed");
        exit(EXIT_FAILURE);
    }

    exec_child(arg_vect);
}