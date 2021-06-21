/*
** EPITECH PROJECT, 2019
** my_rev_params
** File description:
** my rev params
**
*/

int my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, str[i], 1);
        i++;
    }
    return (0);
}

int main(int agrc, char **argv)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr2(argv[i]);
        write(1, '\n', 1);
    }
    return (0);
}
