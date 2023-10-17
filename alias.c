#include "header.h"

int find_alias(const char *alias_name)
{
	int i;
    for (i = 0; i < alias_count; i++) {
        if (strcmp(aliases[i].name, alias_name) == 0) {
            return (i);
        }
    }
    return (-1);
}

void list_all_aliases()
{
	int i;
    for (i = 0; i < alias_count; i++) {
        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

void list_selected_aliases(const char *alias_names)
{
    char *token = strtok((char *)alias_names, " ");
    while (token != NULL) {
        int alias_index = find_alias(token);
        if (alias_index >= 0) {
            printf("%s='%s'\n", aliases[alias_index].name, aliases[alias_index].value);
        } else {
            printf("alias: %s: not found\n", token);
        }
        token = strtok(NULL, " ");
    }
}

void define_alias(const char *alias_name, const char *alias_value) {
    int alias_index = find_alias(alias_name);
    if (alias_index >= 0) {
        strcpy(aliases[alias_index].value, alias_value);
    } else {
        if (alias_count < MAX_ALIAS_COUNT) {
            strcpy(aliases[alias_count].name, alias_name);
            strcpy(aliases[alias_count].value, alias_value);
            alias_count++;
        } else {
            fprintf(stderr, "alias: Too many aliases defined. Maximum limit reached.\n");
        }
    }
}
