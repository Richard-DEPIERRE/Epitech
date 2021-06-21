/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Is it a prime ?
*/

int my_is_prime(int nb)
{
    int count = 2;
    int result = 1;

    if (nb <= 1) {
        return (0);
    }
    while (count < nb && nb > 1 && result == 1) {
        if (nb % count == 0) {
            return (0);
        } else {
            result = 1;
        }
        count++;
    }
    if (result == 1) {
        return (result);
    } else {
        return (0);
    }
}
