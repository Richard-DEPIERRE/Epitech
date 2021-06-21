/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main for minishell
*/

#include "minishell.h"

void initialize_everything(minishell_t *mini)
{
    mini->error = 0;
    mini->execute_error = 0;
    mini->tmp = 0;
    mini->temp = 0;
    mini->size = 4090;
    mini->head = NULL;
    mini->buffer = NULL;
    mini->envi = NULL;
    mini->table = NULL;
}

int while_loop(minishell_t *mini, char **env)
{
    while (mini->error == 0) {
        print_prompt();
        if (getline(&mini->buffer, &mini->size, stdin) < 0) {
            if (isatty(0) == 1)
                write(1, "exit\n", 5);
            exit(0);
        }
        mini->buffer[my_strlength(mini->buffer) - 1] = '\0';
        if (my_strlength(mini->buffer) > 0) {
            mini->table = parse_string(mini->buffer, ' ');
            get_path(mini, env);
            mini->tmp = 0;
            check_if_my_commands(mini);
            execute_file(mini, env);
        }
    }
    return (0);
}

int minishell(char **env)
{
    minishell_t *mini = malloc(sizeof(minishell_t));

    initialize_everything(mini);
    if (!env[0])
        env = create_my_env();
    for (int i = 0; env[i]; i += 1)
        mini->head = add_nodes(env[i], mini->head);
    return (while_loop(mini, env));
}