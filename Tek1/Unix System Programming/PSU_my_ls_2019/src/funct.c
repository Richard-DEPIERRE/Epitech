/*
** EPITECH PROJECT, 2020
** funct
** File description:
** file for needed functions
*/

#include "my_ls.h"

int my_strlen4(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char *my_strcat_mod(char *dest, char *src)
{
    int count = 0;
    int i = 0;
    char *res = NULL;

    count = my_strlen4(dest) ;
    res = malloc(sizeof(char) * (count + my_strlen4(src) + 1));
    while (dest[i] != '\0' && dest != NULL) {
        res[i] = dest[i];
        i += 1;
    }
    for (int j = 0; src[j]; j += 1) {
        res[i] = src[j];
        i += 1;
    }
    res[i] = '\0';
    return (res);
}

void my_putlonglong(long long nb)
{
    char tmp = 0;

    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-\0", 2);
    }
    if (nb >= 10) {
        my_putlonglong(nb / 10);
    }
    nb = nb % 10;
    tmp = nb + 48;
    write(1, &tmp, 1);
}

char **my_strcpy_mod(char **str, char *str2)
{
    int i = 0;
    int count = 0;
    int counter = 0;
    char **tmp;

    for (counter = 0; str[counter]; counter += 1);
    tmp = malloc(sizeof(char *) * (counter + 2));
    for (i = 0; str[i]; i += 1)
        tmp[i] = my_strcpy2(str[i]);
    for (count = 0; str2[count]; count += 1);
    tmp[i] = malloc(sizeof(char) * (count + 1));
    for (int j = 0; str2[j]; j += 1)
        tmp[i][j] = str2[j];
    tmp[i++][count] = '\0';
    tmp[i] = malloc(sizeof(char));
    tmp[i] = NULL;
    return tmp;
}