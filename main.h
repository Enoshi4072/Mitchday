/* Includes */
#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

/* Defines */
#define LINE_BUFFER 1024
#define SIZE_OF_BUFFER 64
#define REDIR_SIZE 2
#define PIPE_SIZE 3
#define MAX_HISTORY_SIZE 128
#define MAX_COMMAND_NAME_LENGTH 128

#define PROMPT_FORMAT "%Y-%m-%d %H:%M:%S "
#define PROMPT_MAX_LENGTH 30

#define TOFILE_DIRECT ">"
#define APPEND_TOFILE_DIRECT ">>"
#define FROMFILE "<"
#define PIPE_OPT "|"

/* Globals */
int running;
/* Initializes the shell */
void init_shell();
/* Return the current working directory */
char *get_current_dir();
/* Initialization in terms of time */
char *prompt();
/* Error reporting */
void error_alert(char *msg);
/* Remove new line character from the end of a string*/
void remove_end_of_line(char *line);
/* handles prints */
int k_puts(const char *s);
/* Reads a string from the stdin */
void read_line(char *line);
/* Parse the input string into arguments */
void parse_command(char *input_string, char **argv, int *wait);
/* Determines if a command has input output re-direction */
int is_redirect(char **argv);
/* Check if an argument contains pipe option */
int is_pipe(char **argv);
/* parses and redirects arguments */
void parse_redirect(char **argv, char **redirect_argv, int redirect_index);
/* parses and executes piped commands */
void parse_pipe(char **argv, char **child01_argv, char **child02_argv, int pipe_index);
/* Executes a child process */
void exec_child(char **argv);
/* Execute a child process and overwrite input from a file */
void exec_child_overwrite_from_file(char **argv, char **dir);
/* execute a child process and overwrite output to a file */
void exec_child_overwrite_to_file(char **argv, char **dir);
/* Executes a child process and appends to output to file */
void exec_child_append_to_file(char **argv, char **dir);
/* Executes a child process that reads input from the main process */
void exec_child_pipe(char **argv_in, char **argv_out);
void exec_parent(pid_t child_pid, int *bg);
/* Set the value of the previous command to the given line of input */
void set_prev_command(char *history, char *line);
/* Retrive the previous command from history */
char *get_prev_command(char *history);
/* Function declarations for builtin commands */

/* Returns the number of built-in commands in the shell */
int simple_shell_num_builtins();
/* Changes the current working directory of the shell process */
int simple_shell_cd(char **argv);
/* Print information about the shell and its available commands. */
int simple_shell_help(char **argv);
/* Terminate the shell. */
int simple_shell_exit(char **args __attribute__((unused)));
/* Display previous commands and run them */
int simple_shell_history(char *history, char **redir_args);
/*  handles input/output redirection in a command */
int simple_shell_redirect(char **args, char **redir_argv);
/* Execute command with pipe */
int simple_shell_pipe(char **args);
/* Executes commands inputed */
void exec_command(char **args, char **redir_argv, int wait, int res);
#endif
