#include "main.h"
/**
 * simple_shell_redirect - Redirects input/output of commands.
 * @command_args: List of arguments to the command.
 * @redirection_args: List of arguments to the redirection operator.
 *
 * Return: 1 if redirection is performed, 0 otherwise.
 */
int simple_shell_redirect(char **command_args, char **redirection_args)
{
    int redirection_operator_index = is_redirect(command_args);

    if (redirection_operator_index != 0)
    {
        parse_redirect(command_args, redirection_args, redirection_operator_index);
        if (strcmp(redirection_args[0], ">") == 0)
        {
            exec_child_overwrite_to_file(command_args, redirection_args);
        }
        else if (strcmp(redirection_args[0], "<") == 0)
        {
            exec_child_overwrite_from_file(command_args, redirection_args);
        }
        else if (strcmp(redirection_args[0], ">>") == 0)
        {
            exec_child_append_to_file(command_args, redirection_args);
        }
        return (1);
    }
    return (0);
}

