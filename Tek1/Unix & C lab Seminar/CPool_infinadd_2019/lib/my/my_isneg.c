/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Print P if positive or null and N if negative
*/

void my_putchar(char c);

int    my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}