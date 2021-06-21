/*
** EPITECH PROJECT, 2019
** cat
** File description:
** my own cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void my_putstr(char *str);

char *reset_string(char *str, int length)
{
    for (int i = 0; i < length; i++)
        str[i] = '\0';
    return (str);
}

int cat(char *filename)
{
    char print[32000] = {0};
    int fd = open(filename, O_RDONLY);

    print[0] = '\0';
    read(fd, print, 32000);
    my_putstr(print);
    close(fd);
    return (0);
}

void cat_no_file()
{
    int length = 0;
    char print[32000];
    
    while (1) {
        reset_string(print, length);
        length = read(0, print, 32000);
        my_putstr(print);
    }
}

void cat_files(int ac, char **av)
{
    if (av[1] == NULL) {
        cat_no_file();
    } else {
        for (int i = 1; i < ac; i++)
            cat(av[i]);
    }
}

int main(int ac, char **av)
{
    cat_files(ac, av);
    return (0);
}
