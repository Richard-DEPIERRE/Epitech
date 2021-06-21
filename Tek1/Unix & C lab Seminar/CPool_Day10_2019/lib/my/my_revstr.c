/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

int my_strlen2(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char *strcpy2(char *dest, char const *src)
{
    int o = 0;
    
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        o = i + 1;
    }
    dest[o] = '\0';
    return (dest);
}

char *my_revstr(char *str)
{
    char dest[my_strlen2(str)];
    int count = 0;

    count = my_strlen2(str) - 1;
    strcpy2(dest, str);
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = dest[count];
        count--;
    }
    return (str);
}
