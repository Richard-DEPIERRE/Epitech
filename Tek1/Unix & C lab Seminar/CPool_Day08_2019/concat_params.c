/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** concat params
*/

#include <stdlib.h>

char *my_strcat(char *dest, char *src);

int my_strlen(char const *str);

char *concat_params(int argc, char **argv)
{
    char *str;
    int a;

    str = malloc((argc + 1) * sizeof(char));
    for (int i = 0; i < argc; i++) {
        str = my_strcat(str, argv[i]);
        a = my_strlen(str);
        str[a] = '\n';
    }
    return (str);
}
