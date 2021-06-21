/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** my strlowcase
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strlowcase(char *str)
{
    char *dest;
	
	dest = malloc(sizeof(*dest) * (my_strlen(str) + 1));
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			dest[i] = str[i] + 32;
		} else {
			dest[i] = str[i];
		}
	}
	return (dest);
}
