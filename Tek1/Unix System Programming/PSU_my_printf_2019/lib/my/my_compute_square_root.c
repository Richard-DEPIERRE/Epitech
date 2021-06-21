/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** find the square root
*/

int    my_compute_square_root(int nb)
{
    int count = 0;
    int result = 0;
    int check = 0;

    if (nb == 0 || nb < 0) {
        return (0);
    } else if (nb == 1) {
        result = 1;
    }
    count = nb - 1;
    while (count > 0 && result == 0) {
        check = count * count;
        if (check == nb) {
            result = count;
        } else {
            count--;
        }
    }
    return (result);
}
