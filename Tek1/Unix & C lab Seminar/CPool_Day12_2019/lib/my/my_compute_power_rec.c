/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** to the power
*/

int    my_compute_power_rec(int nb, int p)
{
    int result = 1;

    if (p >= 1) {
        result = nb * my_compute_power_rec(nb, p-1);
        return (result);
    } else if (p == 0) {
        return (1);
    } else {
        return (0);
    }
}
