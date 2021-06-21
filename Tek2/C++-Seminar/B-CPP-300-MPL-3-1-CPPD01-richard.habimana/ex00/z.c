/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <stdio.h>
#include <unistd.h>

int print_z(void)
{
    write(1, "z\n\0", 2);
    return (0);
}

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
    return print_z();
}