/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** menger
*/

#include "menger.h"
#include "bitmap.h"
#include "drawing.h"

void nothing(void)
{
    return;
}

void write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;

    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

void write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t info;

    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}

void draw_square(uint32_t **img, const point_t *origin,
size_t size, uint32_t color);

void meng(int size, int level, coordinate_t points, unsigned int **img)
{
    point_t point = {size + points.x, size + points.y};
    int col = 0xFF / level;
    int test = ((col & 0xff) << 16) + ((col & 0xff) << 8) + (col & 0xff);
    coordinate_t tmp;

    draw_square(img, &point, size, test);
    for (int a = 0; a < 3 && (level > 1); a += 1)
        for (int b = 0; b < 3; b += 1) {
            (a != 1 || b != 1) ? tmp.x = a * size + points.x : nothing();
            (a != 1 || b != 1) ? tmp.y = b * size + points.y : nothing();
            (a != 1 || b != 1) ? meng(size / 3, level - 1, tmp, img) : nothing() ;
        }
}