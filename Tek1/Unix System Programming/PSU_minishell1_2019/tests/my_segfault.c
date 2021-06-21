/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2019
** File description:
** my_segfault.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    *(int *)0 = 0;
}