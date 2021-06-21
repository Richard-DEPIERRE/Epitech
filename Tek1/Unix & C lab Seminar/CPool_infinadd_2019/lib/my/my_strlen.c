/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** string length
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
