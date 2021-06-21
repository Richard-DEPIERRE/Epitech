/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../PapaXmasElf.hpp"

Test(test_Box , one)
{
    Box bx;
    Box bx2(bx);
    Object obj;
    Box bx3(obj);
    Teddy teddy("hello");
    teddy.isTaken();
    bx.setToy(&teddy);
    LittlePony pony("yoooo");
    pony.isTaken();
    bx2.wrapMeThat(&pony);
    cr_assert_eq(0, bx2.wrapMeThat(&pony) ? 1 : 0);
    bx2.wrapMeThat(&bx3);
    bx2.getToy()->getTitle().c_str();
    bx2.openMe()->getTitle().c_str();
    bx2.closeMe();
    bx.closeMe();
}

Test(test_Box , two)
{
    Box bx;
    Box bx2(bx);
    Object obj;
    Box bx3(obj);
    Teddy teddy("hello");
    bx.setToy(&teddy);
    Teddy teddy2("hello");
    cr_assert_eq(1, bx2.wrapMeThat(&teddy2) ? 1 : 0);
    bx2.wrapMeThat(&teddy2);
    bx2.wrapMeThat(&bx3);
    bx2.getToy()->getTitle().c_str();
    bx2.openMe()->getTitle().c_str();
    bx2.closeMe();
    bx.closeMe();
}

Test(test_Box , three)
{
    Box bx;
    Box bx2(bx);
    Object obj;
    Box bx3(obj);
    Teddy teddy("hello");
    bx.setToy(&teddy);
    Teddy teddy2("hello");
    bx2.wrapMeThat(&teddy2);
    bx2.wrapMeThat(&teddy2);
    cr_assert_eq(0, bx2.wrapMeThat(&bx3) ? 1 : 0);
    bx2.getToy()->getTitle().c_str();
    bx2.openMe()->getTitle().c_str();
    bx2.closeMe();
    bx.closeMe();
}

Test(test_Box , four)
{
    Box bx;
    Box bx2(bx);
    Object obj;
    Box bx3(obj);
    Teddy teddy("hello");
    bx.setToy(&teddy);
    Teddy teddy2("hello");
    bx2.wrapMeThat(&teddy2);
    bx2.wrapMeThat(&teddy2);
    bx2.wrapMeThat(&bx3);
    cr_assert_str_eq("hello", bx2.getToy()->getTitle().c_str());
    bx2.openMe()->getTitle().c_str();
    bx2.closeMe();
    bx.closeMe();
}

Test(test_Box , five)
{
    Box bx;
    Box bx2(bx);
    Object obj;
    Box bx3(obj);
    Teddy teddy("hello");
    bx.setToy(&teddy);
    Teddy teddy2("hello");
    bx2.wrapMeThat(&teddy2);
    bx2.wrapMeThat(&teddy2);
    bx2.wrapMeThat(&bx3);
    bx2.getToy()->getTitle().c_str();
    cr_assert_str_eq("hello", bx2.openMe()->getTitle().c_str());
    bx2.closeMe();
    bx.closeMe();
}
