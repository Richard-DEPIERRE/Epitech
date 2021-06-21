/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** New
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Object *new;
    va_list ap;

    if (!class)
        raise("No Class found");
    va_start(ap, class);
    new = va_new(class, &ap);
    va_end(ap);
    return (new);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *new = NULL;

    if (!class)
        raise("No Class found");
    if (!class->__size__)
        raise("Size is equal to 0");
    new = malloc(class->__size__);
    if (!new)
        raise("No memory given");
    if (!memcpy(new, class, class->__size__))
        raise("Copy did not work");
    if (class->__ctor__)
        class->__ctor__(new, ap);
    return (new);
}

void delete(Object *ptr)
{
    Class *class = (Class *)ptr;

    if (!ptr)
        raise("No Object found");
    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}