/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** my show word array
*/

#include <stdlib.h>

char *my_strcat(char *dest, char *src);

int my_strlen(char const *str);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    char *str;
    int size;
    int end;

    for (size = 0; tab[size] != 0; size++){
    }
    str = malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        str = my_strcat(str, tab[i]);
        end = my_strlen(str);
        str[end] = '\n';
    }
    my_putstr(str);
    return (0);
}
