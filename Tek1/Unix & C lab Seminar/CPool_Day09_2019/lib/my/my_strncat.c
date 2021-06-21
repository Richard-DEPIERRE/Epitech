/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** my strncat
*/

int my_strlen8(char const *str)
{
    int count = 0;

    while(str[count] != '\0') {
        count++;
    }
    return (count);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int count = 0;
    int i = 0;

    count = my_strlen8(dest) ;
    while (src[i] != '\0' && i < nb) {
        dest[count] = src[i];
        i++;
        count++;
    }
    dest[count] = '\0';
    return (dest);
}
