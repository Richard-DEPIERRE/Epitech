/*
** EPITECH PROJECT, 2019
** error_add
** File description:
** add errors
*/

#include <unistd.h>

int check_error2(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            write(2, "Please input valid numbers\n", 28);
            return (1);
        }
    }
}

int error(char **av)
{
    int check = 0;

    if (av[1] == 0 || av[2] == 0){
        write(2, "Not enough arguments\n", 22);
        return (1);
    }
    if (av[1][0] == '-') {
        check = check_error2(av[1] + 1);
        if (check == 1)
            return (1);
    } else if (av[1][0] != '-') {
        check = check_error2(av[1]);
        if (check == 1)
            return (1);
    }
    if (av[2][0] == '-') {
        check = check_error2(av[2] + 1);
        if (check == 1)
            return (1);
    } else if (av[2][0] != '-') {
        check = check_error2(av[2]);
        if (check == 1)
            return (1);
    }
    return (0);
}