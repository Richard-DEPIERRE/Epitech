/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include "../PapaXmasElf.hpp"

Test(test_giftPaper , one)
{
    GiftPaper gift;
    Box box;
    gift.setBox(&box);
    gift.wrapMeThat(&box);
    GiftPaper gift2;
    Box box2;
    Teddy teddy("hello");
    box2.wrapMeThat(&teddy);
    gift2.wrapMeThat(&box2);
    cr_assert_str_eq("Box", gift2.openMe()->getType().c_str());
    gift2.openMe();
    gift2.closeMe();
}

Test(test_giftPaper , two)
{
    GiftPaper gift;
    Box box;
    gift.setBox(&box);
    gift.wrapMeThat(&box);
    GiftPaper gift2;
    Box box2;
    Teddy teddy("hello");
    cr_assert_eq(1, box2.wrapMeThat(&teddy) ? 1 : 0);
    gift2.wrapMeThat(&box2);
    gift2.openMe();
    gift2.openMe();
    gift2.closeMe();
}

Test(test_giftPaper , three)
{
    GiftPaper gift;
    Box box;
    gift.setBox(&box);
    gift.wrapMeThat(&box);
    GiftPaper gift2;
    Box box2;
    Teddy teddy("hello");
    box2.wrapMeThat(&teddy);
    cr_assert_eq(1, gift2.wrapMeThat(&box2) ? 1 : 0);
    gift2.openMe()->getType();
    gift2.openMe();
    gift2.closeMe();
}

Test(test_giftPaper , four)
{
    GiftPaper gift;
    Box box;
    gift.setBox(&box);
    cr_assert_eq(0, gift.wrapMeThat(&box) ? 1 : 0);
    GiftPaper gift2;
    Box box2;
    Teddy teddy("hello");
    box2.wrapMeThat(&teddy);
    gift2.wrapMeThat(&box2);
    gift2.openMe()->getType();
    gift2.openMe();
    gift2.closeMe();
}

Test(test_giftPaper , five)
{
    GiftPaper gift;
    Box box;
    gift.setBox(&box);
    gift.wrapMeThat(&box);
    GiftPaper gift2;
    Box box2;
    Teddy teddy("hello");
    box2.wrapMeThat(&teddy);
    gift2.wrapMeThat(&box2);
    gift2.openMe();
    cr_assert_eq(0, gift2.openMe() ? 1 : 0);
    gift2.openMe();
    gift2.closeMe();
}