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
    {
        if (i->get_name() == "Water")
            side_items.push_back(new Water{i->get_units()});
        else if (i->get_name() == "MilkFoam")
            side_items.push_back(new MilkFoam{i->get_units()});
        else if (i->get_name() == "Sugar")
            side_items.push_back(new Sugar{i->get_units()});
        else if (i->get_name() == "Chocolate")
            side_items.push_back(new Chocolate{i->get_units()});
        else if (i->get_name() == "Cookie")
            side_items.push_back(new Cookie{i->get_units()});
        else if (i->get_name() == "Espresso")
            side_items.push_back(new Espresso{i->get_units()});
        else if (i->get_name() == "Milk")
            side_items.push_back(new Milk{i->get_units()});
        else
            side_items.push_back(new Cinnamon{i->get_units()});
    }
}
void Cappuccino::operator=(const Cappuccino &cap)
{
    if (this != &cap)
    {
        std::cout << price() << "hh" << std::endl;
        // EspressoBased::operator=(cap);
        std::cout << price() << "hh" << std::endl;
        for (const auto &i : side_items)
            delete i;
        side_items.clear();
        std::cout << price() << "hh" << std::endl;
        for (const auto &i : cap.side_items)
        {
            if (i->get_name() == "Water")
                side_items.push_back(new Water{i->get_units()});
            else if (i->get_name() == "MilkFoam")
                side_items.push_back(new MilkFoam{i->get_units()});
            else if (i->get_name() == "Sugar")
                side_items.push_back(new Sugar{i->get_units()});
            else if (i->get_name() == "Chocolate")
                side_items.push_back(new Chocolate{i->get_units()});
            else if (i->get_name() == "Cookie")
                side_items.push_back(new Cookie{i->get_units()});
            else if (i->get_name() == "Espresso")
                side_items.push_back(new Espresso{i->get_units()});
            else if (i->get_name() == "Milk")
                side_items.push_back(new Milk{i->get_units()});
            else if (i->get_name() == "Cinnamon")
                side_items.push_back(new Cinnamon{i->get_units()});
        }
    }
    std::cout << price() << "hh" << std::endl;
}

double Cappuccino::price()
{
    double s{};
    for (const auto &i : ingredients)
        s += (i->price());
    for (const auto &i : side_items)
        s += (i->price());
    return s;
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
