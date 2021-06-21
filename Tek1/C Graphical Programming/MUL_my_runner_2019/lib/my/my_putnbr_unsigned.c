/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my put nbr
*/

void my_putchar(char c);

int my_putnbr_unsigned(unsigned int nb)
{
    if (nb >= 10) {
        my_putnbr_unsigned(nb / 10);
    }
    nb = nb % 10;
    my_putchar(nb + 48);
    return (0);
}