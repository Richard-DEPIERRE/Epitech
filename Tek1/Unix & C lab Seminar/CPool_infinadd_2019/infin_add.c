/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** infinit add nb
*/

#include "include/my.h"
#include "infin_add2.c"
#include "infin_add3.c"
#include "error_add.c"

int negative_or_positive(char *str1, char * str2)
{
    if (str1[0] != '-' && str2[0] != '-')
        return (0);
    if (str1[0] == '-' && str2[0] == '-')
        return (2);
    if (str1[0] == '-' || str2[0] == '-')
        return (1);
}

void infin_add(char *str1, char *str2)
{
    int check = 0;

    check = negative_or_positive(str1, str2);
    if (check == 0)
        infin_add_positives(str1, str2);
    if (check == 1)
        infin_add_positive_negative(str1, str2);
    if (check == 2) {
        my_putchar('-');
        infin_add_positives(str1 + 1, str2 + 1);
    }
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    int check = 0;

    check = error(argv);
    if (check == 0) {
        infin_add(argv[1], argv[2]);
    }
    return (0);
}