/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** my str str
*/

int my_strlen3(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char *my_strstr(char *str, char const *to_find)
{
    int b = -1;
    int i = 0;
    int j = 0;
    int c = 0;
    char copy[my_strlen3(str)];

    if (to_find[0] == '\0') {
        return (str);
    }
    while (str[i] != '\0') {
        if (str[i] == to_find[j]) {
            j++;
        } else {
            j = 0;
        }
        if (to_find[j] != '\0') {
        }
        i++;
    }
    return ('\0');
}