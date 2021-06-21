/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** Display digits in ascending order
*/

#include <unistd.h>

int my_print_digits(void)
{
    int a;

    a = 48;
    while (a <= 57) {
        my_putchar(a);
        a++;
    }
    return (0);
}
