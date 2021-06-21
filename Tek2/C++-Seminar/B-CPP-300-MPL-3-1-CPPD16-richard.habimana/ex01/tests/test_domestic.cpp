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
#include "../EventManager.hpp"

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

static std::list<Event> &createTodoList()
{
    std::list<Event> *todo = new std::list<Event>();
    todo->push_front(Event(19, "The vengeance of the Koala"));
    todo->push_front(Event(20, "The return of the vengeance of the Koala"));
    todo->push_front(Event(21, "The come back of the vengeance of the Koala"));
    todo->push_front(Event(22, "The sequel to the vengeance."));
    todo->push_front(Event(9, "What the hell do you mean 'this morning' ?!"));
    todo->push_front(Event(1, "No, no, you're pushing it now..."));
    return *todo;
}

static void populateEvents(EventManager &em)
{
    em.addEvent(Event(10, "Eat"));
    em.addEvent(Event(12, "Finish the exercises"));
    em.addEvent(Event(12, "Understand the thing"));
    em.addEvent(Event(15, "Set the rights"));
    em.addEvent(Event(8, "Ask what the hell a const_iterator is"));
    em.addEvent(Event(11, "Wash my hands so that my keyboard doesn't smell like kebab"));
}

Test(test_Event , one)
{
    EventManager em;
    OSRedirector oss(std::cout);
    populateEvents(em); em.dumpEvents();
    cr_assert_eq(oss.getContent(), "8: Ask what the hell a const_iterator is\n10: Eat\n11: Wash my hands so that my keyboard doesn't smell like kebab\n12: Finish the exercises\n12: Understand the thing\n15: Set the rights\n");
}

Test(test_Event , two)
{
    EventManager em;
    populateEvents(em); em.dumpEvents();
    OSRedirector oss(std::cout);
    em.removeEventsAt(12); em.dumpEvents();
    cr_assert_eq(oss.getContent(), "8: Ask what the hell a const_iterator is\n10: Eat\n11: Wash my hands so that my keyboard doesn't smell like kebab\n15: Set the rights\n");
}

Test(test_Event , three)
{
    EventManager em;
    populateEvents(em); em.dumpEvents();
    em.removeEventsAt(12); em.dumpEvents();
    OSRedirector oss(std::cout);
    em.addTime(10);
    cr_assert_eq(oss.getContent(), "Ask what the hell a const_iterator is\nEat\n");
}

Test(test_Event , four)
{
    EventManager em;
    populateEvents(em); em.dumpEvents();
    em.removeEventsAt(12); em.dumpEvents();
    em.addTime(10);
    OSRedirector oss(std::cout);
    em.dumpEvents();
    cr_assert_eq(oss.getContent(), "11: Wash my hands so that my keyboard doesn't smell like kebab\n15: Set the rights\n");
}

Test(test_Event , five)
{
    EventManager em;
    populateEvents(em); em.dumpEvents();
    em.removeEventsAt(12); em.dumpEvents();
    em.addTime(10);
    em.dumpEvents();
    OSRedirector oss(std::cout);
    em.addEventList(createTodoList());
    em.dumpEvents();
    cr_assert_eq(oss.getContent(), "11: Wash my hands so that my keyboard doesn't smell like kebab\n15: Set the rights\n19: The vengeance of the Koala\n20: The return of the vengeance of the Koala\n21: The come back of the vengeance of the Koala\n22: The sequel to the vengeance.\n");
}

Test(test_Event , six)
{
    EventManager em;
    populateEvents(em); em.dumpEvents();
    em.removeEventsAt(12); em.dumpEvents();
    em.addTime(10);
    em.dumpEvents();
    em.addEventList(createTodoList());
    em.dumpEvents();
    OSRedirector oss(std::cout);
    em.dumpEventAt(15);
}

Test(test_Event , seven)
{
    EventManager em;
    populateEvents(em); em.dumpEvents();
    em.removeEventsAt(12); em.dumpEvents();
    em.addTime(10);
    em.dumpEvents();
    em.addEventList(createTodoList());
    em.dumpEvents();
    em.dumpEventAt(15);
    OSRedirector oss(std::cout);
    em.addTime(14);
    cr_assert_eq(oss.getContent(), "Wash my hands so that my keyboard doesn't smell like kebab\nSet the rights\nThe vengeance of the Koala\nThe return of the vengeance of the Koala\nThe come back of the vengeance of the Koala\nThe sequel to the vengeance.\n");
}

Test(test_Event , error)
{
    EventManager em;
    EventManager eme(em);
    eme = em;
    Event ev;
    Event m;
    m = ev;
}