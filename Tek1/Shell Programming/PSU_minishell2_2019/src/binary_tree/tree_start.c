/*
** EPITECH PROJECT, 2020
** tree
** File description:
** tree file
*/

#include "minishell.h"

int is_operator(char *str, char *op)
{
    int j = 0;

    if (!op || !str)
        return (-1);
    for (int i = my_strlength(str) - my_strlength(op); i >= 0 ;i -= 1) {
        for (j = my_strlength(op) - 1; op[j] == str[i]; j -= 1)
            i -= 1;
        i += 1;
        j += 1;
        if (j == 0 && str[i] == op[0] && str[i - 1] != str[i])
            return (i + my_strlength(op));
        i -= 1;
        j -= 1;
    }
    return (-1);
}

void get_separator2(char *str, char *separator, separator_t *sep)
{
    for (int i = 0; i < sep->size; i += 1)
        sep->left->str[i] = str[i];
    sep->size += 1;
    sep->left->previous = sep->tmp;
    sep->size2 = my_strlength(str + sep->size + my_strlength(separator));
    sep->right->str = malloc(sizeof(char) * (sep->size2 + 1));
    sep->right->str[sep->size2] = '\0';
    for (int i = sep->size + my_strlength(separator); str[i]; i += 1)
        sep->right->str[i - sep->size - my_strlength(separator)] = str[i];
    sep->right->previous = sep->tmp;
    sep->right->right = NULL;
    sep->right->left = NULL;
    sep->left->right = NULL;
    sep->left->left = NULL;
    sep->tmp->left = sep->left;
    sep->tmp->right = sep->right;
}

void get_separator1(char *str, char *separator, separator_t *sep)
{
    sep->tmp = malloc(sizeof(tree_t));
    sep->left = malloc(sizeof(tree_t));
    sep->right = malloc(sizeof(tree_t));
    sep->size = 0;
    sep->size2 = 0;

    sep->tmp->str = my_strcpy(separator, sep->tmp->str);
    for (sep->size = my_strlength(str) - my_strlength(separator); str[sep->size] != separator[0]; sep->size -= 1);
    for (; str[sep->size] == separator[0]; sep->size -= 1);
}

tree_t *get_separator(char *str, char *separator)
{
    separator_t *sep = malloc(sizeof(separator_t));
    static int loop = 0;

    get_separator1(str, separator, sep);
    if (sep->size == my_strlength(str)) {
        sep->tmp->left = NULL;
        sep->tmp->right = NULL;
        return (sep->tmp);
    }
    sep->left->str = malloc(sizeof(char) * (sep->size + 1));
    sep->left->str[sep->size] = '\0';
    get_separator2(str, separator, sep);
    if (loop == 0)
        sep->tmp->previous = NULL;
    loop += 1;
    return (sep->tmp);
}
tree_t *get_tree(char *str, tree_t *head)
{
    int i = 0;
    int tmp = 0;
    char *op[] = {";", ">", ">>", "<", "<<", "|", NULL};
    tree_t *tmp_tree = head;

    for (i = 0; is_operator(str, op[i]) == -1; i += 1) {
        if (!op[i])
            return (head);
    }
    head = get_separator(str, op[i]);
    if (head->right) {
        head->right = get_tree(head->right->str, head->right);
        head->right->previous = head;
    }
    if (head->left) {
        head->left = get_tree(head->left->str, head->left);
        head->left->previous = head;
    }
    return (head);
}