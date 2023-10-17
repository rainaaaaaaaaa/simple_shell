#include "header.h"

int _strlen(char *s);
size_t strcspn(const char *str, const char *reject);

/**
 * main - check the code
 * @argc: argument count
 * @argv: argument vector
 * Return: the specified exit status
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *command;
	int len, prev_status, operator_index;

    if (argc == 2) {
        *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("File open failed");
            return (1);
        }

      char line[MAX_INPUT_SIZE];
        while (fgets(line, sizeof(line), file)) {
            len = strlen(line);
            if (line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            execute_command(line);
        }

        fclose(file);
    } else {
        char input[MAX_INPUT_SIZE];

        while (1) {
            printf("#cisfun$ ");
            if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
                break;
            }
            input[strcspn(input, "\n")] = '\0';
             *command = strtok(input, "&&||");
            prev_status = 0;
            while (command != NULL) {
                if (prev_status == 0) {
                    operator_index = strcspn(command, "&&||");
                    if (command[operator_index] == '&&') {
                        prev_status = execute_command(command);
                    } else if (command[operator_index] == '||') {
                        prev_status = execute_command(command) ? 0 : 1;
                    } else {
                        prev_status = execute_command(command);
                    }
                }
                command = command + strlen(command) + 1;
            }
        }
    }

    return (exit_status);
}
