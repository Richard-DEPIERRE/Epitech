/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

void temporary_one(char **table, char **table2, char c, order_t *order)
{
    for (int i = 0; table[i]; i += 1) {
        if (table[i][0] == c) {
            order->tmp += 1;
            order->pos = i;
            break;
        }
    }
    if (order->tmp == 1) {
        table2[order->a] = malloc(sizeof(char) *
        (my_strlength(table[order->pos]) + 1));
        table2[order->a][my_strlength(table[order->pos])] = '\0';
        table2[order->a] = my_strcpy(table[order->pos], table2[order->a]);
        order->a += 1;
    }
    order->tmp = 0;
}

int temporary_two(int tmp, char c)
{
    if (c == '*' && tmp == 0)
        tmp = 1;
    return (tmp);
}

int my_getch(void)
{
    struct termios oldt;
    struct termios newt;
    int ch = 0;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return (ch);
}