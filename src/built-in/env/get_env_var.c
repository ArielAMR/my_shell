/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** get_env_var.c
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

char *get_env_var(linked_list_t **env, char *var)
{
    char *buff = NULL;
    linked_list_t *tmp = NULL;
    char *line = NULL;
    char *result = NULL;

    if (env == NULL || var == NULL)
        return NULL;
    tmp = *env;
    while (tmp != NULL) {
        line = my_strdup(tmp->line);
        buff = strtok_r(line, "=", &line);
        if (my_strcmp(buff, var) == 0) {
            result = my_strdup(strtok_r(NULL, "", &line));
            free(buff);
            return result;
        }
        free(buff);
        tmp = tmp->next;
    }
    return NULL;
}
