/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** 
*/

#include <string.h>
#include <stdio.h>

void    my_swap2(char *a, char *b)
{
    int copy_number = 0;
    
    copy_number = *a;
    *a = *b;
    *b = copy_number;
}

int    my_strlen2(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}

char     *my_evil_str(char *str)
{
    int string_length = 0;
    int count = 0;
    
    string_length = my_strlen2(str) - 1;
    while  (0 + count  <  string_length - count ) {
        my_swap2(&str[0 + count], &str[string_length - count]); 
        count++;
    }
    return (str);
}

    
