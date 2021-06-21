/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** Write a function that displays, in ascending order, all the numbers composed by three different digits numbers
*/

#include <unistd.h>

int    print_number(char a, char b, char c)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    my_putchar(',');
    my_putchar(' ');
    return (0);
}

void print_final_numbers()
{
    my_putchar(55);
    my_putchar(56);
    my_putchar(57);
}

int    my_print_comb(void)
{
    unsigned int a = 48;
    unsigned int b = 49;
    unsigned int c = 50;
    print_number(a, b, c);
    while (a < 54 ) {
        if (b == 56 && c == 57 && a < 55){
            a++;
            b = a + 1;
            c = b + 1;
            print_number(a, b, c);
        }
        //print_number(a, b, c);
        while (c < 57) {
            c++;
            print_number(a, b, c);
        }
        b++;
        c = b + 1;
        print_number(a, b, c);
    }
    print_final_numbers();
}
