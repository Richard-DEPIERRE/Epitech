/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it.c
** File description:
** To the !
*/

int my_compute_factorial_it(int nb)
{
    int c = 1;
    int a = nb;

    if (nb == 0) {
        c = 1;
    } else if (nb < 0) {
        c = 0;
    } else if (nb > 0) {
        while (a > 0) {
            c = c * a;
            a--;
        }
    }
    return (c);
}
