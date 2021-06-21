/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** menger
*/

#include "menger.h"
#include "bitmap.h"
#include "drawing.h"

uint16_t swap(uint16_t val)
{
    return (val << 8) | (val >> 8 );
}

void make_bmp_header(bmp_header_t *header , size_t size)
{
    header->magic = swap(0x424D);
    header->_app2 = 0;
    header->size = sizeof(bmp_header_t)+sizeof(bmp_info_header_t)+size*size*4;
    header->offset = 54;
    header->_app1 = 0;
}

void make_bmp_info_header(bmp_info_header_t *header , size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}