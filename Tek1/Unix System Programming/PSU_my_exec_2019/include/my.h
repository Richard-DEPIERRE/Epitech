/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <linux/stat.h>
#include <grp.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>


void my_putchar(char c);

int my_isneg(int nb);

char *my_putnbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_is_prime(int nb);

char *my_revstr(char *str);

int my_showmen(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *tab, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char *src);

int my_strcmp(char const *s1, char const *s2);

char *my_my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

char **my_str_to_word_array(char *str);

int my_putnbr_base(int nbr, char *base);

int my_putnbr_unsigned(unsigned int nb);

int my_putnbr_base_long(long long nbr, char *base);

int my_putnull(int nb);

int my_putstr_mod(char const *str);