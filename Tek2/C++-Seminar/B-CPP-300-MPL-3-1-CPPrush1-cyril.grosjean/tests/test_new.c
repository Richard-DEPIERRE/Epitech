/*
** EPITECH PROJECT, 2021
** Cyril, Richard, Alexis, Jean-Louis
** File description:
** test_new
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../raise.h"
#include "../new.h"
#include "../object.h"
#include "../player.h"
#include "../int.h"

Test(new, should_create_int_class)
{
    Object *integer;

    integer = new(Int, 8);
    cr_assert_not_null(integer);
    delete(integer);
}