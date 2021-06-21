/*
** EPITECH PROJECT, 2021
** cpp_rush1
** File description:
** char
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "new.h"
#include "object.h"
#include "char.h"

typedef struct
{
    Class base;
    char c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *string = NULL;
    int i = 0;

    if (!this)
        raise("CharClass is null");
    string = calloc(20, sizeof(char));
    if (!string)
        raise("Error calloc");
    i = snprintf(string, 20, "<Char (%c)>", this->c);
    if (i < 0)
        raise("Error snprintf");
    return (string);
}

static Object *Char_add(const CharClass *this, const CharClass *toAdd)
{
    Object *result;

    if (!this || !toAdd)
        raise("CharClass is null");
    result = new(Char, this->c + toAdd->c);
    return (result);
}

static Object *Char_sub(const CharClass *this, const CharClass *toSub)
{
    Object *result;

    if (!this || !toSub)
        raise("CharClass is null");
    result = new(Char, this->c - toSub->c);
    return (result);
}

static Object *Char_mul(const CharClass *this, const CharClass *other)
{
    Object *result;

    if (!this || !other)
        raise("CharClass is null");
    result = new(Char, this->c * other->c);
    return (result);
}

static Object *Char_div(const CharClass *this, const CharClass *other)
{
    Object *result;

    if (!this || !other)
        raise("CharClass is null");
    if (other->c == 0)
        raise("Cannot divide by 0 !");
    result = new(Char, this->c / other->c);
    return (result);
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("CharClass is null");
    return (this->c == other->c);
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("CharClass is null");
    return (this->c > other->c);
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("CharClass is null");
    return (this->c < other->c);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class *Char = (const Class *)&_description;