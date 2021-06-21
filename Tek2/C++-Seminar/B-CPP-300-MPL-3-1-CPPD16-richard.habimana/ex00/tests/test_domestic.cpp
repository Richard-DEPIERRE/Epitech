/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include <ostream>
#include <iostream>
#include "../DomesticKoala.hpp"

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;

    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

Test(test_KoalaAction , Goto)
{
    KoalaAction action;
    DomesticKoala dk(action);
    dk.learnAction('>', &KoalaAction::goTo);
    OSRedirector oss(std::cout);
    dk.doAction('>', "{EPITECH.}");
    cr_assert_eq(oss.getContent(), "I go to: {EPITECH.}\n");
}

Test(test_KoalaAction , eat)
{
    KoalaAction action;
    DomesticKoala dk(action);
    dk.learnAction('<', &KoalaAction::eat);
    OSRedirector oss(std::cout);
    dk.doAction('<', "a DoubleCheese");
    cr_assert_eq(oss.getContent(), "I eat: a DoubleCheese\n");
}

Test(test_KoalaAction , reproduce)
{
    KoalaAction action;
    DomesticKoala dk(action);
    dk.learnAction('X', &KoalaAction::reproduce);
    OSRedirector oss(std::cout);
    dk.doAction('X', "a Seagull");
    cr_assert_eq(oss.getContent(), "I attempt to reproduce with: a Seagull\n");
}

Test(test_KoalaAction , sleep)
{
    KoalaAction action;
    DomesticKoala dk(action);
    DomesticKoala pk(dk);
    pk = dk;
    dk.learnAction('#', &KoalaAction::sleep);
    pk.learnAction('#', &KoalaAction::sleep);
    OSRedirector oss(std::cout);
    dk.doAction('#', "The end of the C++ pool, and an Astek burning on a stake");
    pk.unlearnAction('#');
    pk.unlearnAction('p');
    cr_assert_eq(oss.getContent(), "I sleep, and dream of: The end of the C++ pool, and an Astek burning on a stake\n");
}

Test(test_KoalaAction , errors)
{
    KoalaAction action;
    DomesticKoala dk(action);
    DomesticKoala pk(dk);
    pk = dk;
    pk.unlearnAction('#');
    pk.unlearnAction('p');
}