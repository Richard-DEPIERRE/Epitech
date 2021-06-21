/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** menger
*/

#include "menger.h"
#include "bitmap.h"
#include "drawing.h"

int my_getnbr(char const *str)
{
    int minus_count = 0;
    int i = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i += 1) {
        if (str[i] == '-')
            minus_count += 1;
    }
    for (; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            break;
        nb = nb * 10 + (str[i] - 48);
    }
    if (minus_count % 2 == 1)
        nb = nb * (-1);
    return (nb);
}

int check_errors(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if (my_getnbr(av[2]) < 0 || my_getnbr(av[2]) % 3 != 0)
        return (84);
    if (my_getnbr(av[3]) < 0 || my_getnbr(av[3]) > my_getnbr(av[2]) / 3)
        return (84);
    return (0);
}

void initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
}

void create_bitmap_from_buffer(size_t size, unsigned int *buffer, char *str)
{
    int fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int main(int ac, char **av)
{
    if (check_errors(ac, av) == 84) {
        write(2, "menger_face file_name size level\n", 34);
        return (84);
    }

    size_t size = (size_t)(my_getnbr(av[2]));
    unsigned int *buffer = malloc(size * size * sizeof(*buffer));
    unsigned int **img = malloc(size * sizeof(*img));
    coordinate_t points;
    points.x = 0;
    points.y = 0;
    initialize_image(size, buffer, img);
    meng(my_getnbr(av[2]) / 3, my_getnbr(av[3]), points, img);
    create_bitmap_from_buffer(size, buffer, av[1]);
    return (0);
}