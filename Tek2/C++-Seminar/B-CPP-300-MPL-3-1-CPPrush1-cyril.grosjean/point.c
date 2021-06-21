/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "new.h"
#include "object.h"
#include "point.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *x = NULL;
    char *y = NULL;
    char *string = NULL;
    int i = 0;

    if (!this)
        raise("PointClass is null");
    x = malloc(sizeof(char) * (11));
    sprintf(x, "%d", this->x);
    y = malloc(sizeof(char) * (11));
    sprintf(y, "%d", this->y);
    string = malloc(sizeof(char) * (13 + 10 + 10));
    i = snprintf(string, (13 + 10 + 10), "<Point (%d, %d)>",
    this->x, this->y);
    free(x);
    free(y);
    if (i < 0)
        raise("Error snprintf");
    return (string);
}

static Object *Point_add(const PointClass *this, const PointClass *other)
{
    Object *result;

    if (!this || !other)
        raise("PointClass is null");
    result = new(Point, this->x + other->x, this->y + other->y);
    return (result);
}

static Object *Point_sub(const PointClass *this, const PointClass *other)
{
    Object *result;

    if (!this || !other)
        raise("PointClass is null");
    result = new(Point, this->x - other->x, this->y - other->y);
    return (result);
}

static Object *Point_mul(const PointClass *this, const PointClass *other)
{
    Object *result;

    if (!this || !other)
        raise("PointClass is null");
    result = new(Point, this->x * other->x, this->y * other->y);
    return (result);
}

static Object *Point_div(const PointClass *this, const PointClass *other)
{
    Object *result;

    if (!this || !other)
        raise("PointClass is null");
    if (other->x == 0 || other->y == 0)
        raise("Cannot divide by 0 !");
    result = new(Point, this->x / other->x, this->y / other->y);
    return (result);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = (binary_operator_t)&Point_mul,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
