/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** to the !
*/

int    my_compute_factorial_rec(int nb)
{
    int result = 0;

    if (nb > 1)
    {
        result = nb * my_compute_factorial_rec(nb - 1);
        return (result);
    } else if (nb == 0 || nb == 1) {
        return (1);
    } else {
        return (0);
    }
}
