/*
** EPITECH PROJECT, 2019
** rush1-1
** File description:
** rush task 01
*/

void line_up(int x)
{
    for (int count_x = 1; count_x <= x; count_x++) {
        if (count_x == x) {
            my_putchar('o');
            my_putchar('\n');
        } else if (count_x == 1) {
            my_putchar('o');
        } else {
            my_putchar('-');
        }
    }
}

void line_down(int x)
{
    for (int count_x = 1; count_x <= x; count_x++) {
        if (count_x == x) {
            my_putchar('o');
            my_putchar('\n');
        } else if (count_x == 1) {
            my_putchar('o');
        } else {
            my_putchar('-');
        }
    }
}

void middle(int x)
{
    for (int count_x = 1; count_x <= x; count_x++) {
        if (count_x == x) {
            my_putchar('|');
            my_putchar('\n');
        } else if (count_x == 1) {
            my_putchar('|');
        } else {
            my_putchar(' ');
        }
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0 || x > 2147483647 || y > 2147483647) {
        write(2, "Invalid size\n", 13);
    }
    for (int count_y = 1; count_y <= y; count_y++) {
        if (count_y == 1) {
            line_up(x);
        } else if (count_y == y) {
            line_down(x);
        } else {
            middle(x);
        }
    }
}
