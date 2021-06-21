/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

typedef struct info_s {
    int lol;
    int bolle;
    int check;
    float speed;
    float max;
    float direction;
    char **tab;
    float *pos;
} info_t;

char *my_strcat(char *dest, char *src);
char **str_to_word_array(char *str);
int my_strlen(char *str);
