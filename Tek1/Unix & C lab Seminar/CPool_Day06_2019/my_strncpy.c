/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    if (n >= 0) {
        for (i = 0; i < n ; i++) {
            dest[i] = src[i];
        }
        if (n < i) {
            dest[i] = '\0';
        }
    }
    return (dest);
}
