/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** 
*/

int my_put_nbr(int nb )
{
    int r = 0;
    int t = 0;
    int o = 1;
    int p = 0;
    int m = 1;
    int n = 0;

    while (nb != 0) {
        nb = nb / 10;
        r++;
    }
    while (r - o >= 0) {
        n = r - o;
        while (n > 0) {
            m = m * 10;
            n--;
        }
        t = nb / m;
        p = t + 48;
        my_putchar(p);
        nb = nb - t * m;
    }
    return (0);
}
