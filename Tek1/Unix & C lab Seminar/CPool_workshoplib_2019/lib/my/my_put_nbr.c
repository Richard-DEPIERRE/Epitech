/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
		
	}
	nb = nb % 10;
	my_putchar(nb + 48);
	return (0);
}