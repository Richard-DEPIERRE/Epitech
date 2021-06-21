/*
** EPITECH PROJECT, 2019
** my_putstr_mod
** File description:
** copy string modified
*/

#include "../../include/my.h"

int my_putstr_mod(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] >= 32 && str[i] <= 126){
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base(str[i], "01234567");
        }
        i += 1;
    }
    return (0);
}