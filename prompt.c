#include "main.h"
/**
 * get_current_dir - Get the current working directory.
 *
 * Return: Pointer to the current working directory.
 */
char *dir_get() {
    char cwd[FILENAME_MAX];
    char*result = getcwd(cwd, sizeof(cwd));
    return result;
}

/**
 * Initializes the Shell prompt in the format YYYY-MM-dd <space> hour:minute:second <space> default shell name <space> >
 * @param None
 * @return A pointer to the prompt string
 */
char *prompt_entry() {
    static char *_prompt = NULL;
    char* username;

    if (_prompt == NULL) {
        _prompt = malloc(M_L_PROMPT * sizeof(char));
        if (_prompt == NULL) {
            perror("Error: Unable to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    /* Clear prompt */
    memset(_prompt, 0, M_L_PROMPT);

    /* Append default shell name */
    username = getenv("USER");
    strncat(_prompt, username, strlen(username));

    return _prompt;
}
