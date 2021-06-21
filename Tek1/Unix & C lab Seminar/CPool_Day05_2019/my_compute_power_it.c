/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** To the power
*/

int    my_compute_power_it(int nb, int p)
{
    int result = 1;

    if (p >= 1) {
        while (p > 0) {
            result = result * nb;
            p--;
        }
        return (result);
    } else if (p == 0){
        return (1);
    } else {
        return (0);
    }
}
