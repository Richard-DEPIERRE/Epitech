/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** vertex
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "new.h"
#include "object.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *x = NULL;
    char *y = NULL;
    char *z = NULL;
    char *string = NULL;

    if (!this)
        raise("VertexClass is null");
    x = malloc(sizeof(char) * (11));
    sprintf(x, "%d", this->x);
    y = malloc(sizeof(char) * (11));
    sprintf(y, "%d", this->y);
    z = malloc(sizeof(char) * (11));
    sprintf(z, "%d", this->z);
    string = malloc(sizeof(char) * (16 + strlen(x) + strlen(y) + strlen(z)));
    snprintf(string, (16 + strlen(x) + strlen(y) + strlen(z)), \
    "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    free(x);
    free(y);
    free(z);
    return (string);
}

static Object *Vertex_add(const VertexClass *this, const VertexClass *toAdd)
{
    Object *result;

    if (!this || !toAdd)
        raise("VertexClass is null");
    result = new(Vertex, this->x + toAdd->x, this->y + toAdd->y,
    this->z + toAdd->z);
    return (result);
}

static Object *Vertex_sub(const VertexClass *this, const VertexClass *toSub)
{
    Object *result;

    if (!this || !toSub)
        raise("VertexClass is null");
    result = new(Vertex, this->x - toSub->x, this->y - toSub->y,
    this->z - toSub->z);
    return (result);
}

static Object *Vertex_mul(const VertexClass *this, const VertexClass *toMul)
{
    Object *result;

    if (!this || !toMul)
        raise("VertexClass is null");
    result = new(Vertex, this->x * toMul->x, this->y * toMul->y,
    this->z * toMul->z);
    return (result);
}

static Object *Vertex_div(const VertexClass *this, const VertexClass *toDiv)
{
    Object *result;

    if (!this || !toDiv)
        raise("VertexClass is null");
    if (toDiv->x == 0 || toDiv->y == 0 || toDiv->z == 0)
        raise("Cannot divide by 0 !");
    result = new(Vertex, this->x / toDiv->x, this->y / toDiv->y,
    this->z / toDiv->z);
    return (result);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;