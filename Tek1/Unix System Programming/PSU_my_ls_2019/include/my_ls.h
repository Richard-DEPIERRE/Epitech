/*
** EPITECH PROJECT, 2019
** my_ls.h
** File description:
** h file for my_ls
*/

#ifndef MY_LS
#define MY_LS

#include "my.h"

typedef struct begin_s {
    char **folders;
    char **options;
    int l_flag;
    int r_flag;
    int t_flag;
    int error;
    int check;
} begin_t;

typedef struct l_function_s {
    int total;
    char **type;
    char **permissions;
    long *hard_link;
    char **user;
    char **groups;
    long long *allocated_space;
    char **time;
    char **name;
} l_function_t;

typedef struct bridge_s {
    DIR *dir;
    struct dirent *sd;
    l_function_t *table;
    int i;
    struct stat sb;
    struct passwd *pass;
    struct group *groups;
    int size;
    int nb_folders;
} bridge_t;

typedef struct check_s {
    int count_l;
    int count_R;
    int count_d;
    int count_r;
    int count_t;
} check_t;

int my_ls(int ac, char **av);

int get_path(int ac, char **av, begin_t *begin);

char **my_strcpy_mod(char **str, char *str2);

int check2(char c, char c2, int *count);

int check3(char c);

char *my_strcpy2(char *src);

void no_directories(char *str, bridge_t *bridge);

void put_everything_in_time_order(char **array, char *str);

void directories(begin_t *begin, bridge_t **all_directories);

int operator_is_present(char **str, char c);

char *my_strcat_mod(char *dest, char *src);

char *get_permissions(struct stat sb);

char *get_type(struct stat sb);

int get_size(char *str);

int my_strlen4(char const *str);

void r_flag_function(char *src, char *str, begin_t *begin);

void l_flag_function(char *str, begin_t *begin);

void t_flag_function(char *src, char *str, begin_t *begin);

void print_folder(char *str);

void print_name(char *str);

void my_putlong(long nb);

void my_putlonglong(long long nb);

void my_putnb(int nb);

void begin_l_flag_function(char *str, begin_t *begin);

char **sort_array(char **aray, long long *order);

void print_l_flag(struct stat sb, struct passwd *pass,
struct group *groups, char *str);

void print_function_l(struct stat sb, struct passwd *pass,
struct group *groups, struct dirent *sd);

char **modifie_two(DIR *dir, char *str, begin_t *begin, struct dirent *sd);

char **modifie_three(char *str, begin_t *begin, struct dirent *sd);

long long get_month2(char *str);

int count_dir(DIR *dir, char *str, begin_t *begin);

int get_total(DIR *dir, char *str);

#endif