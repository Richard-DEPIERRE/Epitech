/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** Display lowercas alphabet in reverse
*/

#include <unistd.h>

int    my_print_revalpha(void)
{
    int a;
    
    a = 122;
    while (a >= 97) {
        my_putchar(a);
        a--;
    }
    return (0);
}
