/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** get_input.c
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static void write_history(char *command, char *user)
{
    char *path = my_strcat_inf(3, "/home/", user, "/.mysh_history");
    int fd = 0;

    if (path == NULL)
        return;
    fd = open(path, O_RDWR | O_APPEND);
    free(path);
    if (fd == -1)
        return;
    write(fd, command, my_strlen(command));
}

static void prompt(prompt_t *variables)
{
    char wd[PATH_MAX_LEN];

    getcwd(wd, PATH_MAX_LEN);
    if (variables->user == NULL)
        variables->user = my_strdup("$ ");
    mini_printf("\033[1;35m%s\n", wd);
    if (variables->status == 0)
        mini_printf("\033[32m%d\033[0m - ", variables->status);
    else
        mini_printf("\033[31m%d\033[0m - ", variables->status);
    mini_printf("\033[1;36m%s➤ \033[0m", variables->user);
}

int get_input(char **command, char ***args, size_t *size, prompt_t *variables)
{
    char *tmp = NULL;

    if (isatty(STANDARD_INPUT) == 1)
        prompt(variables);
    if (getline(command, size, stdin) == EOF)
        return EPI_ERROR;
    write_history(*command, variables->user);
    tmp = format_cmd(*command);
    if (tmp == NULL)
        return EPI_ERROR;
    *args = my_str_to_word_array(tmp, " \n\t", "\"\'");
    free(tmp);
    if (*args == NULL)
        return EPI_ERROR;
    return EPI_SUCCESS;
}
