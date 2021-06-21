/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush2-richard.habimana
** File description:
** PapaXmasElf
*/

#include "PapaXmasElf.hpp"
#include "Wrap.hpp"

PapaXmasElf::PapaXmasElf()
{
    _hand = nullptr;
    _table = createTableRand();
    _conveyorBelt = createConveyorBeltRand();
    _loop = 0;
}

PapaXmasElf::~PapaXmasElf()
{
    delete _table;
    delete _conveyorBelt;
}

void PapaXmasElf::Take(workstation ws, int i)
{
    if (ws == TABLE) {
        _hand = _table->Take(i);
        std::cout << "Elf has taken " << _hand->getTitle() << "in his hands" << std::endl;
        return;
    }
    std::cout << "Elf has taken " << _hand->getTitle() << "in his hands" << std::endl;
    _hand = _conveyorBelt->Take();
}

void PapaXmasElf::Put(workstation ws, Object *object)
{
    if (ws == TABLE) {
        if (_table->Put(object))
            std::cout << "Elf put " << object->getTitle() << "on the table" << std::endl;
        else {
            _table->~PapaXmasTableRand();
            delete _table;
            std::cerr << "o'pa ere's somin' wron' in da box!" << std::endl;
        }
        return;
    }
    if (_conveyorBelt->Put(object))
        std::cout << "Elf put " << object->getTitle() << "on the conveyor belt" << std::endl;
}

void PapaXmasElf::In()
{
    _conveyorBelt->In();
}

int PapaXmasElf::LookToy()
{
    std::array<std::string, 11> objects = _table->look();
    for (int i = 0; i < 11; i++) {
        if (objects[i] == "Toy")
            return (i);
    }
    return (-1);
}

int PapaXmasElf::LookBox()
{
    std::array<std::string, 11> objects = _table->look();
    for (int i = 0; i < 11; i++) {
        if (objects[i] == "Box")
            return (i);
    }
    return (-1);
}

int PapaXmasElf::LookFullBox()
{
    std::array<std::string, 11> objects = _table->look();
    for (int i = 0; i < 11; i++) {
        if (objects[i] == "FullBox") {
            return (i);
        }
    }
    return (-1);
}

int PapaXmasElf::LookGiftPaper()
{
    std::array<std::string, 11> objects = _table->look();
    for (int i = 0; i < 11; i++) {
        if (objects[i] == "GiftPaper")
            return (i);
    }
    return (-1);
}

int PapaXmasElf::LookFullGift()
{
    std::array<std::string, 11> objects = _table->look();
    for (int i = 0; i < 11; i++) {
        if (objects[i] == "FullGift")
            return (i);
    }
    return (-1);
}

void PapaXmasElf::startToWork()
{
    static int pos = 0;
    std::string filename("Gift" + std::to_string(pos) + ".xml");
    std::ofstream outfile(filename);
    outfile << "<?xml version=\"1.0\"?>\n<gift class_id=\"0\" tracking_level=\"0\" version=\"1\">\n\t<item class_id=\"1\" tracking_level=\"0\" version=\"1\">\n";
    outfile.close();
    Look(filename);
    outfile.open(filename, std::ios::out | std::ios::app);
    outfile << "</gift>";
    outfile.close();
    pos++;
    _loop = 0;
}

void PapaXmasElf::Look(const std::string filename)
{
    std::array<std::string, 11> objects = _table->look();
    if (LookFullGift() != -1) {
        std::cout << "Taking Gift..." << std::endl;
        _hand = _table->Take(LookFullGift());
        std::cout << "Put Gift on Conveyor Belt..." << std::endl;
        _conveyorBelt->Put(_hand);
        if (_conveyorBelt->Out(filename, &_loop)) {
            std::cout << "Sending gift to Santa" << std::endl;
            std::cout << "e speex 'n' XML" << std::endl;
        }
        std::cout << std::endl;
        Look(filename);
    } else if (LookToy() != -1 && LookBox() != -1){
        std::cout << "Wraping..." << std::endl;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        std::cout << "Take Toy..." << std::endl << "Wrap Toy in Box" << std::endl;
        Wrap *wg = new Box((Box)(*(_table->Take(LookBox()))));
        if (_table->GetObject(LookToy())->getType() == "Teddy") {
            Toy *ty = new Teddy(_table->GetObject(LookToy())->getTitle());
            wg->wrapMeThat(ty);
            wg->setType("Box");
        } else {
            Toy *ty = new LittlePony(_table->GetObject(LookToy())->getTitle());
            wg->wrapMeThat(ty);
            wg->setType("Box");
        }
        _table->Put(wg);
        _table->FullBox(LookBox());
        _table->MakeNull(LookToy());
        std::cout << std::endl;
        Look(filename);
    } else if (LookFullBox() != -1 && LookGiftPaper() != -1) {
        std::cout << "Wraping..." << std::endl;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        std::cout << "Take Full Box.." << std::endl << "Wrap Full Box in Gift Paper" << std::endl;
        Wrap *giftPaper = new GiftPaper((GiftPaper)(*(_table->Take(LookGiftPaper()))));
        giftPaper->wrapMeThat((Box *)(_table->GetObject(LookFullBox())));
        giftPaper->setType("GiftPaper");
        _table->Put(giftPaper);
        _table->FullGift(LookGiftPaper());
        _table->MakeNull(LookFullBox());
        std::cout << std::endl;
        Look(filename);
    } else if ((LookFullBox() != -1  && LookGiftPaper() == -1) || (LookToy() != -1 && LookBox() == -1)) {
        std::cout << "Pushing IN..." << std::endl;
        _conveyorBelt->In();
        std::cout << "Generating Wrap..." << std::endl;
        _hand = _conveyorBelt->Take();
        std::cout << "Taking Wrap..." << std::endl;
        if (_table->Put(_hand) == false) {
            return;
        }
        std::cout << "Put Wrap on Table" << std::endl;
        std::cout << std::endl;
        Look(filename);
    } else
        std::cerr << "o'pa ere 's somin ' wron ' in da box !" << std::endl;
}