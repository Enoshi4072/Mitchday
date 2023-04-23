#include "main.h"
/**
 * execute_pipe_command - Executes a pipe command.
 * @args: List of arguments to the command.
 *
 * Return: 1 if pipe is performed, 0 otherwise.
 */
int simple_shell_pipe(char **args)
{
    int pipe_index = is_pipe(args);

    if (pipe_index != 0)
    {
        char *child_args_1[PIPE_SIZE];
        char *child_args_2[PIPE_SIZE];
        parse_pipe(args, child_args_1, child_args_2, pipe_index);
        exec_child_pipe(child_args_1, child_args_2);
        return (1);
    }
    return (0);
}
