/*
** EPITECH PROJECT, 2019
** hidden_p
** File description:
** main file for hidden_p
*/

#include "hidden_p.h"

int check_errors(int ac)
{
    if (ac != 3) {
        write(2, "Usage: ./hiddenp needle haystack\n", 33);
        return 84;
    }
    return 0;
}

int check_string(char *str1, char *str2)
{
    int count = 0;

    for (int i = 0; str2[i]; i += 1)
	if (str2[i] == str1[count])
	    count += 1;
    if (str1[count] == '\0')
	return (1);
    else
	return (0);
}

int hidden_p(int ac, char **av)
{
    int check = 0;

    if (check_errors(ac) == 84)
	return (84);
    check = check_string(av[1], av[2]);
    if (check == 1)
	write(1, "1\n", 2);
    else
	write(1, "0\n", 2);
    return (0);
}
