/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** change_for_home.c
*/

#include "linked_list.h"
#include "mysh.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static int is_wave(char *path)
{
    int count = 0;

    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == GO_HOME)
            count++;
        else
            return count;
    return count;
}

static bool is_user(char *user)
{
    char *file = open_file(PASSWD);
    char **lines = my_str_to_word_array(file, "\n\0", "");
    char *user_line = NULL;

    if (file == NULL || lines == NULL)
        return false;
    free(file);
    for (int i = 0; lines[i] != NULL; i++) {
        user_line = strtok(lines[i], ":");
        if (my_strcmp(user_line, user) == 0) {
            free_list(lines);
            return true;
        }
    }
    free_list(lines);
    return false;
}

static char *change_path_users(char *path)
{
    char *complete = NULL;
    char *user = NULL;

    path++;
    user = my_strdup_delim(path, '/');
    if (user == NULL)
        return NULL;
    if (is_user(user) == false) {
        mini_printf_error("Unknown user: %s.\n", user);
        return NULL;
    }
    path += my_strlen(user);
    complete = my_strcat_inf(3, "/home/", user, path);
    free(user);
    return complete;
}

static char *change_path_main_user(char *path, linked_list_t **head)
{
    char *home = NULL;
    char *complete = NULL;

    home = get_env_var(head, HOME_VAR);
    if (home == NULL)
        return NULL;
    path++;
    complete = my_strcat_inf(2, home, path);
    free(home);
    return complete;
}

char *change_for_home(char *path, linked_list_t **head)
{
    if (path == NULL)
    return NULL;
    if (is_wave(path) != 1)
        return NULL;
    if (path[1] == '\0' || path[1] == '/')
        return change_path_main_user(path, head);
    return change_path_users(path);
}
