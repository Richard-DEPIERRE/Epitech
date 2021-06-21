/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** main
*/

#include "PapaXmasElf.hpp"

Object **MyUnitTests()
{
   Object **res = new Object *[2];
    res[0] = new LittlePony("happy pony");
    res[1] = new Teddy("cuddles");
    return (res);
}

Object *MyUnitTests(Object **objects)
{
    Toy *teddy = new Teddy(objects[0]->getTitle());
    Wrap *box = new Box((Box)(*(objects[1])));
    Wrap *giftPaper = new GiftPaper((GiftPaper)(*(objects[2])));
    box->wrapMeThat(teddy);
    giftPaper->wrapMeThat(box);
    return giftPaper;
}

int main(void)
{
    std::srand(std::time(nullptr));
    PapaXmasElf elf;
    elf.startToWork();
    PapaXmasElf elf2;
    elf2.startToWork();
    PapaXmasElf elf3;
    elf3.startToWork();
    PapaXmasElf elf4;
    elf4.startToWork();
    return (0);
}
