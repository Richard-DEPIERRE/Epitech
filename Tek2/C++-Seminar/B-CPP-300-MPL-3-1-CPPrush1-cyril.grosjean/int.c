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
#include "player.h"
#include "int.h"

typedef struct
{
    Class base;
    int num;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->num = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    char *string = NULL;

    if (!this)
        raise("IntClass is null");
    string = calloc(20, sizeof(char));
    if (!string)
        raise("Error calloc");
    snprintf(string, 20, "<Int (%d)>", this->num);
    return (string);
}

static Object *Int_add(const IntClass *this, const IntClass *other)
{
    Object *result;

    if (!this || !other)
        raise("IntClass is null");
    result = new(Int, this->num + other->num);
    return (result);
}

static Object *Int_sub(const IntClass *this, const IntClass *other)
{
    Object *result;

    if (!this || !other)
        raise("IntClass is null");
    result = new(Int, this->num - other->num);
    return (result);
}

static Object *Int_mul(const IntClass *this, const IntClass *other)
{
    Object *result;

    if (!this || !other)
        raise("IntClass is null");
    result = new(Int, this->num * other->num);
    return (result);
}

static Object *Int_div(const IntClass *this, const IntClass *other)
{
    Object *result;

    if (!this || !other)
        raise("IntClass is null");
    if (other->num == 0)
        raise("Cannot divide by 0 !");
    result = new(Int, this->num / other->num);
    return (result);
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("IntClass is null");
    return (this->num == other->num);
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("IntClass is null");
    return (this->num > other->num);
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("IntClass is null");
    return (this->num < other->num);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .num = 0
};

const Class *Int = (const Class *)&_description;
