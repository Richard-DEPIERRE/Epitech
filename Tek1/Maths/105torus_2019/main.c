/*
** EPITECH PROJECT, 2019
** 105torus
** File description:
** 105torus
*/


#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void h_text(void)
{
    write(1, "USAGE\n\t./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n\t", 54);
    write(1, "opt\tmethod option:\n\t\t\t1 for the bisection method\n\t\t\t2 for Newton’s method\n", 77);
    write(1, "\t\t\t3 for the secant method\n\t", 29);
    write(1, "a[0-4]\tcoefficients of the equation\n\t", 38);
    write(1, "n\tprecision (the application of the polynomial to the solution should\n", 71);
    write(1, "\t\tbe smaller than 10ˆ-n)", 26);
}

float calc_function(char **av, float nb)
{
    return (atof(av[2]) + (atof(av[3]) * nb) + (atof(av[4]) * pow(nb, 2)) + (atof(av[5]) * pow(nb, 3)) + (atof(av[6]) * pow(nb, 4)));
}

int check_zeros(float nb, int check)
{
    int tmp = 0;

    for (int i = 0; i < check; i += 1) {
        nb *= 10;
        tmp = floor(nb);
        tmp %= 10;
        if (tmp != 0)
            return 1;
    }
    return (0);
}

void print_my_nb(float nb, int precision)
{
    static int count = 0;
    int tmp = 0;
    int tmp2 = 0;
    int i = 0;

    tmp = floor(nb);
    printf("x = %d.", tmp);
    if (nb < 0)
        nb *= (-1);
    for (; i < precision - 1; i += 1) {
        if (check_zeros(nb, precision - i) == 0) {
            break;
        }
        nb *= 10;
        tmp = floor(nb);
        tmp %= 10;
        printf("%d", tmp);
    }
    if (i == precision - 1) {
        if (count == 0) {
            count += 1;
        }else {
            nb *= 10;
            tmp = floor(nb);
            tmp %= 10;
            if (tmp == 0) {
                nb *= 10;
                tmp2 = floor(nb);
                tmp2 %= 10;
                if (tmp2 >= 5)
                    tmp = 1;
                else
                    tmp = 0;
            }
            printf("%d", tmp);
        }
    }
    printf("\n");
}

void bisection_method(char **av)
{
    float a = 0;
    float b = 1;
    float c = 0.5;
    float nb = 1;
    float one = 0;
    float two = 0;
    int precision = atoi(av[7]);
    int multiplication = 10;

    for (int i = 0; i < precision - 1; i += 1)
        multiplication *= 10;
    while (1){
        nb = calc_function(av, c);
        // printf("%.6f\n", c);
        print_my_nb(c, precision);
        if (floor(multiplication*nb)/multiplication == 0)
            break;
        else {
            one = calc_function(av, a);
            two = calc_function(av, b);
            if (one * nb < 0) {
                b = c;
                c = (a + b) / 2;
            } else if (two * nb < 0) {
                a = c;
                c = (a + b) / 2;
            } else {
                break;
            }
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 8 && ac != 2)
        return (84);
    if (ac == 2 && (av[1][0] != '-' || av[1][1] != 'h'))
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        h_text();
        return (0);
    }
    if (av[1][0] != '3' && av[1][0] != '2' && av[1][0] != '1')
        return (84);
    float a = atof(av[1]);
    if (a <= 0)
        return (84);
    if (av[1][0] == '1')
        bisection_method(av);
    if (av[1][0] == '2')
        return (0);
    if (av[1][0] == '3')
        return (0);
    return (0);
}