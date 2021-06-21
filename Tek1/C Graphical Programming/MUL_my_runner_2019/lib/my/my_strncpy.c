/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
