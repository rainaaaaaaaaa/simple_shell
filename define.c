#include "header.h"

char *replace_variables(const char *command)
{
    char *result = (char *)malloc(strlen(command) * 2);
    int result_index, command_index;

    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return (NULL);
    }

    result_index = 0;
    command_index = 0;
    while (command[command_index] != '\0') {
        if (command[command_index] == '$') {
            if (command[command_index + 1] == '?') {
            
                sprintf(result + result_index, "%d", last_command_status);
                result_index += snprintf(NULL, 0, "%d", last_command_status);
                command_index += 2;
            } else if (command[command_index + 1] == '$') {
     
                sprintf(result + result_index, "%d", getpid());
                result_index += snprintf(NULL, 0, "%d", getpid());
                command_index += 2;
            } else {
               
                result[result_index++] = command[command_index++];
            }
        } else {
         
            result[result_index++] = command[command_index++];
        }
    }
    result[result_index] = '\0';
    return (result);
}

int execute_command(const char *command)
{
	int status;
	char *expanded_command, *comment_start, *old_dir;
    if (command[0] == '\0') {
        return (0);
    }

    expanded_command = replace_variables(command);
    if (expanded_command == NULL) {
        return (1);
    }

    comment_start = strchr(expanded_command, '#');
    if (comment_start != NULL) {
        *comment_start = '\0';
    }

    if (strncmp(expanded_command, "exit", 4) == 0) {

        if (sscanf(expanded_command + 4, "%d", &status) == 1) {
            exit_status = status;
        }
        free(expanded_command);
        return (1);
    }
   
    else if (strncmp(expanded_command, "setenv", 6) == 0) {
        char variable[MAX_INPUT_SIZE];
        char value[MAX_INPUT_SIZE];
        if (sscanf(expanded_command + 6, "%s %s", variable, value) == 2) {
            if (setenv(variable, value, 1) != 0) {
                fprintf(stderr, "setenv: Error setting environment variable.\n");
            }
        } else {
            fprintf(stderr, "setenv: Incorrect syntax. Usage: setenv VARIABLE VALUE\n");
        }
        free(expanded_command);
        return (0);
    }
  
    else if (strncmp(expanded_command, "unsetenv", 8) == 0) {
        char variable[MAX_INPUT_SIZE];
        if (sscanf(expanded_command + 8, "%s", variable) == 1) {
            if (unsetenv(variable) != 0) {
                fprintf(stderr, "unsetenv: Error unsetting environment variable.\n");
            }
        } else {
            fprintf(stderr, "unsetenv: Incorrect syntax. Usage: unsetenv VARIABLE\n");
        }
        free(expanded_command);
        return (0);
    }

    else if (strncmp(expanded_command, "cd", 2) == 0) {
        char new_directory[MAX_INPUT_SIZE];
        if (sscanf(expanded_command + 2, "%s", new_directory) == 1) {
            if (strcmp(new_directory, "-") == 0) {
                old_dir = getenv("OLDPWD");
                if (old_dir == NULL) {
                    fprintf(stderr, "cd: OLDPWD not set.\n");
                } else {
                    if (chdir(old_dir) != 0) {
                        perror("cd");
                    }
                    printf("%s\n", old_dir);
                }
            } else {
                char current_dir[PATH_MAX];
                if (getcwd(current_dir, PATH_MAX) == NULL) {
                    perror("getcwd");
                } else {
                    if (chdir(new_directory) != 0) {
                        perror("cd");
                    } else {
                        setenv("OLDPWD", current_dir, 1);
                        setenv("PWD", new_directory, 1);
                    }
                }
            }
        } else {
            fprintf(stderr, "cd: Incorrect syntax. Usage: cd [DIRECTORY]\n");
        }
        free(expanded_command);
        return (0);
    }
 
    else if (strcmp(expanded_command, "env") == 0) {
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
        free(expanded_command);
        return (0);
    }
    else if (strncmp(expanded_command, "alias", 5) == 0) {
        const char *alias_arguments = expanded_command + 5;
        if (alias_arguments[0] == '\0' || alias_arguments[0] == ' ') {
            list_all_aliases();
        } else {
            if (alias_arguments[0] == ' ') {
                list_selected_aliases(alias_arguments + 1);
            } else {
                char *alias_name = strtok((char *)alias_arguments, "=");
                char *alias_value = strtok(NULL, "=");
                if (alias_name != NULL && alias_value != NULL) {
                    define_alias(alias_name, alias_value);
                }
            }
        }
        free(expanded_command);
        return (0);
    } else {
        int alias_index = find_alias(expanded_command);
        if (alias_index >= 0) {
            free(expanded_command);
            return (execute_command(aliases[alias_index].value));
        } else {
            if (access(expanded_command, X_OK) == 0) {
                pid_t pid = fork();

                if (pid < 0) {
                    perror("Fork failed");
                    exit(1);
                } else if (pid == 0) {
                    char *args[MAX_INPUT_SIZE];
                    int i = 0;
                    char *token = expanded_command;
                    while (1) {
                        args[i++] = token;
                        token = strchr(token, ' ');

                        if (token == NULL) {
                            break;
                        }
                        *token = '\0';
                        token++;
                    }
                    args[i] = NULL;

                    execvp(args[0], args);
                    perror(args[0]);
                    exit(1);
                } else {
                    int status;
                    waitpid(pid, &status, 0);
                    last_command_status = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
                    free(expanded_command);
                    return (last_command_status);
                }
            } else {
                printf("%s: command not found\n", expanded_command);
                free(expanded_command);
                return (1);
            }
        }
    }
}
