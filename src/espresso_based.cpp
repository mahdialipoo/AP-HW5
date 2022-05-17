#include "espresso_based.h"

#include <typeinfo>
#include <iostream>
std::vector<Ingredient *> &EspressoBased::get_ingredients() { return ingredients; }
EspressoBased::~EspressoBased()
{
    for (const auto &i : ingredients)
        delete i;
    ingredients.clear();
}
EspressoBased::EspressoBased() = default;
EspressoBased::EspressoBased(const EspressoBased &esp)
{
    for (const auto &i : esp.ingredients)
        if ((typeid(*i).name() + 1) == "Water")
            ingredients.push_back(new Water{i->get_units()});
        else if ((typeid(*i).name() + 1) == "MilkFoam")
            ingredients.push_back(new MilkFoam{i->get_units()});
        else if ((typeid(*i).name() + 1) == "MilkFoam")
            ingredients.push_back(new Sugar{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Sugar")
            ingredients.push_back(new Chocolate{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Chocolate")
            ingredients.push_back(new Cookie{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Cookie")
            ingredients.push_back(new Espresso{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Espresso")
            ingredients.push_back(new Milk{i->get_units()});
        else
            ingredients.push_back(new Cinnamon{i->get_units()});
}
void EspressoBased::operator=(const EspressoBased &esp)
{
    name = esp.get_name();
    for (const auto &i : ingredients)
        delete i;
    ingredients.clear();
    for (const auto &i : esp.ingredients)
        if ((typeid(*i).name() + 1) == "Water")
            ingredients.push_back(new Water{i->get_units()});
        else if ((typeid(*i).name() + 1) == "MilkFoam")
            ingredients.push_back(new MilkFoam{i->get_units()});
        else if ((typeid(*i).name() + 1) == "MilkFoam")
            ingredients.push_back(new Sugar{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Sugar")
            ingredients.push_back(new Chocolate{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Chocolate")
            ingredients.push_back(new Cookie{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Cookie")
            ingredients.push_back(new Espresso{i->get_units()});
        else if ((typeid(*i).name() + 1) == "Espresso")
            ingredients.push_back(new Milk{i->get_units()});
        else
            ingredients.push_back(new Cinnamon{i->get_units()});
}
/*
void EspressoBased::brew(){}*/