#include "mocha.h"
#include <iostream>
Mocha::~Mocha()
{
    for (const auto &i : side_items)
        delete i;
    side_items.clear();
}
Mocha::Mocha() : EspressoBased(), side_items{}
{
    std::vector<Ingredient *> p;
    Milk *p1{new Milk{2}};
    MilkFoam *p2{new MilkFoam{1}};
    Espresso *p3{new Espresso{2}};
    Chocolate *p4{new Chocolate{1}};
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    get_ingredients() = p;
}
Mocha::Mocha(const Mocha &mch) : EspressoBased(mch)
{
    for (const auto &i : mch.side_items)
        if ((typeid(*i).name() + 1) == "Water")
            side_items.push_back(new Water{i->get_units()});
        else if ((typeid(*i).name() + 1) == "MilkFoam")
            side_items.push_back(new MilkFoam{i->get_units()});
        else if ((typeid(*i).name() + 1) == "MilkFoam")
            side_items.push_back(new Sugar{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Sugar")
            side_items.push_back(new Chocolate{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Chocolate")
            side_items.push_back(new Cookie{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Cookie")
            side_items.push_back(new Espresso{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Espresso")
            side_items.push_back(new Milk{i->get_units()});
        else
            side_items.push_back(new Cinnamon{i->get_units()});
}
void Mocha::operator=(const Mocha &mch)
{
    if (this != &mch)
    {
        EspressoBased::operator=(mch);
        for (const auto &i : side_items)
            delete i;
        side_items.clear();
        for (const auto &i : mch.side_items)
            if ((typeid(*i).name() + 1) == "Water")
                side_items.push_back(new Water{i->get_units()});
            else if ((typeid(*i).name() + 1) == "MilkFoam")
                side_items.push_back(new MilkFoam{i->get_units()});
            else if ((typeid(*i).name() + 1) == "Sugar")
                side_items.push_back(new Sugar{i->get_units()});
            else if ((typeid(*i).name() + 1) == "Chocolate")
                side_items.push_back(new Chocolate{i->get_units()});
            else if ((typeid(*i).name() + 1) == "Cookie")
                side_items.push_back(new Cookie{i->get_units()});
            else if ((typeid(*i).name() + 1) == "Espresso")
                side_items.push_back(new Espresso{i->get_units()});
            else if ((typeid(*i).name() + 1) == "Milk")
                side_items.push_back(new Milk{i->get_units()});
            else
                side_items.push_back(new Cinnamon{i->get_units()});
    }
}

double Mocha::price()
{
    double s{};
    for (const auto &i : ingredients)
        s += (i->price());
    for (const auto &i : side_items)
        s += (i->price());
    return s;
}
std::string Mocha::get_name() const { return "Mocha"; }

void Mocha::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}
std::vector<Ingredient *> &Mocha::get_side_items() { return side_items; }
