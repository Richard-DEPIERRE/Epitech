/*
** EPITECH PROJECT, 2019
** my_str_len
** File description:
** return string length
*/

int my_strlen(char const *str);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return (i);
}
