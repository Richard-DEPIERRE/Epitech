/*
** EPITECH PROJECT, 2019
** cat_strcat
** File description:
** Put string inside string inside string over and over
*/

char *my_strcat(char *dest, char *src);
char *get_str(int nb);

char *cat_strcat(char *str, int width, int height)
{
    char *res;
    char *w = get_str(width);
    char *h = get_str(height);
    res = my_strcat(my_strcat(my_strcat(str, w), " "), h);
    return (res);
}
