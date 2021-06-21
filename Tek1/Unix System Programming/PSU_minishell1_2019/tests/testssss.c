/*
** EPITECH PROJECT, 2020
** testssss
** File description:
** testsss
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    write(1, "hello\n\0", 7);
    return (0);
}