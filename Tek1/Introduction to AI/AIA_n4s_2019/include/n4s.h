/*
** EPITECH PROJECT, 2019
** n4s.h
** File description:
** h file for n4s
*/

#ifndef n4s1
#define n4s1

#include "my.h"

typedef struct node_s {
    char *str;
    char *name;
    struct node_s *next;
} node_t;

typedef struct parse_s {
    char **table;
    int count;
    int j;
} parse_t;

typedef struct n4s_s {
    int error;
    int execute_error;
    int tmp;
    int temp;
    size_t size;
    char *buffer;
    char **envi;
    char **table;
    node_t *head;
} n4s_t;

int n4s(char **env);
char **create_my_env(void);
void print_prompt(void);
void get_path(n4s_t *mini, char **env);
void execute_file(n4s_t *mini, char **env);
void check_if_my_commands(n4s_t *mini);
void setenv_function(n4s_t *mini);
void unsetenv_function(n4s_t *mini);
void env_function(n4s_t *mini);
void cd_function(n4s_t *mini);

node_t *delete_node(char *str, node_t *head);
node_t *add_node_at_end(char *str, node_t *head);
node_t *add_nodes(char *str, node_t *head);
void display(node_t *head);
void display_reverse(node_t *head);

int my_strlength(char *str);
int my_strcmp(char *str, char *str2);
int my_strcmp_mod(char *str, char *str2, char c);
char *my_strcpy(char *src, char *dest);
char **parse_string(char *str, char c);
int count_arguments(char *str, char c);
char *clean_string(char *str);

void wheel_dir(info_t *info, char *tmp);
void car_forward(info_t *info, char *tmp);
void car_backward(info_t *info, char *tmp);
void get_distance(info_t *info, size_t size, char *tmp);

#endif