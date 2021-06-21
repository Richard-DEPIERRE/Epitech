/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef EX05
#define EX05

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

typedef union __attribute__((packed)) foo_s {
    struct {
        int16_t foo;
        union{
            int16_t bar;
            int16_t foo;
        }bar;
    }foo;
    int32_t bar;
} foo_t;

#endif