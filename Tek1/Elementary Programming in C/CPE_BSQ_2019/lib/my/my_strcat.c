/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my str cat
*/

int my_strlen4(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char *my_strcat(char *dest, char *src)
{
    int count = 0;
    int i = 0;

    count = my_strlen4(dest) ;
    while (src[i] != '\0') {
        dest[count] = src[i];
        i++;
        count++;
    }
    dest[count] = '\0';
    return (dest);
}