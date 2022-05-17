#include "cappuccino.h"
#include <iostream>

Cappuccino::Cappuccino() : EspressoBased(), side_items{}
{
    std::vector<Ingredient *> p;
    Milk *p1{new Milk{2}};
    MilkFoam *p2{new MilkFoam{1}};
    Espresso *p3{new Espresso{2}};
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    get_ingredients() = p;
}
Cappuccino::Cappuccino(const Cappuccino &cap) : EspressoBased(cap)
{
    for (const auto &i : cap.side_items)
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
void Cappuccino::operator=(const Cappuccino &cap)
{
    if (this != &cap)
    {
        EspressoBased::operator=(cap);
        for (const auto &i : side_items)
            delete i;
        side_items.clear();
        for (const auto &i : cap.side_items)
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

double Cappuccino::price()
{
    double s{};
    for (const auto &i : side_items)
        s += (i->price());
    return s + 55.0;
}
std::string Cappuccino::get_name() const { return "Cappuccino"; }
Cappuccino::~Cappuccino()
{
    for (const auto &i : side_items)
        delete i;
    side_items.clear();
}
void Cappuccino::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}
std::vector<Ingredient *> &Cappuccino::get_side_items() { return side_items; }
