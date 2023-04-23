#include "main.h"
/**
 * simple_shell_exit - Exits the shell by setting the running flag to 0.
 * @args: An array of strings containing the arguments passed to the exit command.
 *
 * Return: 0 (not used).
 */
int simple_shell_exit(char **args __attribute__((unused))) {
    running = 0;
    return running;
}
