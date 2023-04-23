#include "main.h"
/**
 * exec_child_append_to_file - Executes a child process with output redirected to a file with append mode.
 * @argv: Array of strings containing the command and its arguments.
 * @dir: Array of strings containing the redirection arguments.
 */
void exec_child_append_to_file(char **arg_vect, char **dest) {    
    int output_fd = -1;
    if (access(dest[0], F_OK) != -1) {
        output_fd = open(dest[0], O_WRONLY | O_APPEND);
    }
    if (output_fd == -1) {
        perror("Error: REDIRECTION TO OUTPUT FAILED");
        exit(EXIT_FAILURE);
    }
    dup2(output_fd, STDOUT_FILENO);
    if (close(output_fd) == -1) {
        perror("Error: 	CLOSING FAILED");
        exit(EXIT_FAILURE);
    }
    exec_child(arg_vect);
}
/* void exec_parent(pid_t child_pid, int *bg) {} */

/**
 * exec_child_pipe - Performs communication between two commands via Pipe
 * @argv_in: array of arguments for child 1
 * @argv_out: array of arguments for child 2
 *
 * Return: void
 */
void exec_child_pipe(char **argsin, char **argsout)
{
    int f_desc[2];
    if (pipe(f_desc) == -1)
    {
        perror("Error: Piping failed");
        exit(EXIT_FAILURE);
    }

    /* child 1 exec input from main process
     * write to child 2
     */
    if (fork() == 0)
    {
        dup2(f_desc[1], STDOUT_FILENO);
        close(f_desc[0]);
        close(f_desc[1]);
        exec_child(argsin);
        exit(EXIT_SUCCESS);
    }

    /* child 2 exec output from child 1
     * read from child 1
     */
    if (fork() == 0)
    {
        dup2(f_desc[0], STDIN_FILENO);
        close(f_desc[1]);
        close(f_desc[0]);
        exec_child(argsout);
        exit(EXIT_SUCCESS);
    }

    close(f_desc[0]);
    close(f_desc[1]);
    wait(0);
    wait(0);
}
