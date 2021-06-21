/*
** EPITECH PROJECT, 2021
** Cyril, Richard, Alexis, Jean-Louis
** File description:
** float
*/

#include "float.h"
#include "new.h"
#include "object.h"

typedef struct {
    Class base;
    float number;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->number = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    char *string = NULL;

    if (!this)
        raise("FloatClass is null");
    string = calloc(30, sizeof(char));
    if (!string)
        raise("Error calloc");
    snprintf(string, 30, "<Float (%f)>",
    this->number);
    return (string);
}

static Object *Float_add(const FloatClass *this, const FloatClass *toAdd)
{
    Object *result;

    if (!this || !toAdd)
        raise("FloatClass is null");
    result = new(Float, this->number + toAdd->number);
    return (result);
}

static Object *Float_sub(const FloatClass *this, const FloatClass *toSub)
{
    Object *result;

    if (!this || !toSub)
        raise("FloatClass is null");
    result = new(Float, this->number - toSub->number);
    return (result);
}

static Object *Float_mul(const FloatClass *this, const FloatClass *toMul)
{
    Object *result;

    if (!this || !toMul)
        raise("FloatClass is null");
    result = new(Float, this->number * toMul->number);
    return (result);
}

static Object *Float_div(const FloatClass *this, const FloatClass *toDiv)
{
    Object *result;

    if (!this || !toDiv)
        raise("FloatClass is null");
    if (toDiv->number == 0)
        raise("Cannot divide by 0 !");
    result = new(Float, this->number / toDiv->number);
    return (result);
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("FloatClass is null");
    return (this->number == other->number);
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("FloatClass is null");
    return (this->number > other->number);
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("FloatClass is null");
    return (this->number < other->number);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .number = 0.0
};

const Class *Float = (const Class *)&_description;