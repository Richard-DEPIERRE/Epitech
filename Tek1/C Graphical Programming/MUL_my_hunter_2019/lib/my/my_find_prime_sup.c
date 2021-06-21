/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** find th enext prime number
*/

int my_is_prime2(int nb)
{
    int count = 2;
    int result = 1;

    if (nb <= 1)
        return (0);
    while (count < nb && nb > 1 &&  result == 1) {
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

int my_find_prime_sup(int nb)
{
    int result = 0;
    int count = 0;
    int prime_or_not = 0;

    count = nb;
    while (result == 0) {
        prime_or_not = my_is_prime2(count);
        if (prime_or_not == 0) {
            result = 0;
        } else if (prime_or_not == 1) {
            result = count;
        }
        count++;
    }
    if (nb <= 1) {
        result = 2;
    }
    return (result);
}
