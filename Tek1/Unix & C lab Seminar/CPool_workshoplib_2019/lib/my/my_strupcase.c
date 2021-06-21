/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** my strupcase
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strupcase(char *str)
{
	char *dest;
	
	dest = malloc(sizeof(*dest) * (my_strlen(str) + 1));
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			dest[i] = str[i] - 32;
		} else {
			dest[i] = str[i];
		}
	}
	return (dest);
}
