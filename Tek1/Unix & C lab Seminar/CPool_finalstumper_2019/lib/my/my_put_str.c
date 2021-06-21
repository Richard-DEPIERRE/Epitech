/*
** EPITECH PROJECT, 2019
** my_put_str
** File description:
** print a string
*/

int my_putstr(char const *str);
void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}
