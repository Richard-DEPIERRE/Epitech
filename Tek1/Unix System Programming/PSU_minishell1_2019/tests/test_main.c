/*
** EPITECH PROJECT, 2019
** test_hiden_p
** File description:
** testing my hiden_p
*/

#include "minishell.h"

Test(test_matchsticks, error_1)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char *env[5] = {
    "PATH=/bin",
    "PWD=/home/uichaa/PSU_minishell1_2019",
    "HOME=/home/uichaa",
    "OLDPWD=/home/uichaa",
    NULL
    };
    cr_redirect_stdout();
    fprintf(f_stdin, "ls -l\ncd ..\ncd -\nsetenv a b\nsetenv c\nunsetenv c\n");
    fclose(f_stdin);
    cr_assert_eq(minishell(env), 0);
}

Test(test_matchsticks, error_2)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char *env[5] = {
    "PATH=/bin",
    "PWD=/home/uichaa/PSU_minishell1_2019",
    "HOME=/home/uichaa",
    "OLDPWD=/home/uichaa",
    NULL
    };
    cr_redirect_stdout();
    fprintf(f_stdin, "cd\nsetenv PATH\nenv\nsetenv\nls\n/bin/ls\n./testes");
    fclose(f_stdin);
    cr_assert_eq(minishell(env), 0);
}

Test(test_matchsticks, error_3)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char *env[5] = {
    "PATH=/bin",
    "PWD=/home/uichaa/PSU_minishell1_2019",
    "HOME=/home/uichaa",
    "OLDPWD=/home/uichaa",
    NULL
    };
    cr_redirect_stdout();
    fprintf(f_stdin, "./a.out\ncd hello\nunsetenv o\nsetenv i'p*-(j dizhj\n");
    fclose(f_stdin);
    cr_assert_eq(minishell(env), 0);
}

Test(test_matchsticks, error_4)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char *env[1] = {
    NULL
    };
    cr_redirect_stdout();
    fprintf(f_stdin, "cd\nsetenv PATH\nenv\nsetenv\nls\n/bin/ls\n");
    fclose(f_stdin);
    cr_assert_eq(minishell(env), 0);
}

Test(test_matchsticks, error_5)
{
    FILE *f_stdin = cr_get_redirected_stdin();
    char *env[5] = {
    "PATH=/bin",
    "PWD=/home/uichaa/PSU_minishell1_2019",
    "HOME=/home/uichaa",
    "OLDPWD=/home/uichaa",
    NULL
    };
    cr_redirect_stdout();
    fprintf(f_stdin, "cd -\nsetenv baptiste bg\nenv    \t\t\n  ls  \t -l\n\n");
    fclose(f_stdin);
    cr_assert_eq(minishell(env), 0);
}