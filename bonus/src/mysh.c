/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-ariel.amriou
** File description:
** mysh.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static int change_old_pwd(linked_list_t **env)
{
    char *path = get_env_var(env, OLDPWD_VAR);

    if (path == NULL)
        return EPI_SUCCESS;
    free(path);
    if (change_or_create(OLDPWD_VAR, NULL, env) == EPI_ERROR)
        return EPI_ERROR;
    return EPI_SUCCESS;
}

static int free_all(char *command,
    char **args, linked_list_t **env, char *user)
{
    if (isatty(STANDARD_INPUT) == 1)
        mini_printf("exit\n");
    free(command);
    free_list(args);
    free(user);
    delete_linked_list(env);
    return 0;
}

int mysh(linked_list_t **env)
{
    char *command = NULL;
    char **args = NULL;
    prompt_t variables = {get_env_var(env, USER_VAR), 0};
    size_t size = 0;

    if (env == NULL || change_old_pwd(env) == EPI_ERROR)
        return EPI_ERROR;
    while (get_input(&command, &args, &size, &variables) == EPI_SUCCESS) {
        variables.status = exec_proper_function(args, env, variables.status);
        free_list(args);
        args = NULL;
    }
    free_all(command, args, env, variables.user);
    return variables.status;
}
