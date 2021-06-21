/*
** EPITECH PROJECT, 2019
** rush1_4
** File description:
** Rush 1 Assignement 4
*/

void line(int x, char char1, char char2, char char3)
{
    for (int count_x = 1; count_x <= x; count_x++) {
        if (count_x == x) {
            my_putchar(char2);
            my_putchar('\n');
        } else if (count_x == 1) {
            my_putchar(char1);
        } else {
            my_putchar(char3);
        }
    }
}

void make_pattern(int count_y, int x, int y)
{
    if (count_y == 1) {
        line(x, 'A', 'C', 'B');
    } else if (count_y == y) {
        line(x, 'A', 'C', 'B');
    } else {
        line(x, 'B', 'B', ' ');
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0 || x > 2147483647 || y > 2147483647) {
        write(2, "Invalid size\n", 13);
    } else if (x != 1 && y != 1) {
        for (int count_y = 1; count_y <= y; count_y++) {
            make_pattern(count_y, x, y);
        }
    } else {
        for (int count_y = 1; count_y <= y; count_y++) {
            line(x, 'B', 'B', 'B');
        }
    }
}
