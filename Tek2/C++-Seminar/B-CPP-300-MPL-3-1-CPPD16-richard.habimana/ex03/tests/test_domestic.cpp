/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD01-richard.habimana
** File description:
** z
*/

#include <criterion/criterion.h>
#include <ostream>
#include <cstdlib>
#include <iostream>
#include "../Ratatouille.hpp"

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

Test(test_Ratatouille , one)
{
    Ratatouille rata; rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
    rata.addVegetable('x');
    OSRedirector oss(std::cout);
    std::cout << "We taste: " << rata.kooc() << std::endl;
    cr_assert_eq(oss.getContent(), "We taste: Tomato42123.321x\n");
}

Test(test_Ratatouille , two)
{
    Ratatouille rata; rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
    rata.addVegetable('x');
    rata.addSauce("Bolognese"); rata.addSpice(3.14);
    OSRedirector oss(std::cout);
    std::cout << "C'mon, taste that: " << rata.kooc() << std::endl;
    cr_assert_eq(oss.getContent(), "C'mon, taste that: Tomato42123.321xBolognese3.14\n");
}

Test(test_Ratatouille , third)
{
    Ratatouille rata; rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
    rata.addVegetable('x');
    rata.addSauce("Bolognese"); rata.addSpice(3.14);
    Ratatouille glurp(rata);
    glurp.addVegetable('p'); glurp.addVegetable('o');
    glurp.addSauce("Tartar");
    OSRedirector oss(std::cout);
    std::cout << "And now: " << glurp.kooc() << std::endl;
    cr_assert_eq(oss.getContent(), "And now: poTartar123.321xBolognese3.14\n");
}

Test(test_Ratatouille , fourth)
{
    Ratatouille rata; rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
    rata.addVegetable('x');
    rata.addSauce("Bolognese"); rata.addSpice(3.14);
    Ratatouille glurp(rata);
    glurp.addVegetable('p'); glurp.addVegetable('o');
    glurp.addSauce("Tartar");
    rata = glurp;
    OSRedirector oss(std::cout);
    std::cout << "I'll taste again, it's sooo good: " << rata.kooc() << std::endl;
    cr_assert_eq(oss.getContent(), "I'll taste again, it's sooo good: poTartar123.321xBolognese3.14\n");
}