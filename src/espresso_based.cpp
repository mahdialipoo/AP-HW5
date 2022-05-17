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
    {
        if (i->get_name() == "Water")
            ingredients.push_back(new Water{i->get_units()});
        else if (i->get_name() == "MilkFoam")
            ingredients.push_back(new MilkFoam{i->get_units()});
        else if (i->get_name() == "Sugar")
            ingredients.push_back(new Sugar{i->get_units()});
        else if (i->get_name() == "Chocolate")
            ingredients.push_back(new Chocolate{i->get_units()});
        else if (i->get_name() == "Cookie")
            ingredients.push_back(new Cookie{i->get_units()});
        else if (i->get_name() == "Espresso")
            ingredients.push_back(new Espresso{i->get_units()});
        else if (i->get_name() == "Milk")
            ingredients.push_back(new Milk{i->get_units()});
        else
            ingredients.push_back(new Cinnamon{i->get_units()});
    }
}
void EspressoBased::operator=(const EspressoBased &esp)
{
    if (this != &esp)
    {
        name = esp.get_name();
        std::cout << price() << "gg" << std::endl;
        for (const auto &i : ingredients)
            delete i;
        ingredients.clear();
        std::cout << price() << "gg" << ingredients.size() << std::endl;
        for (const auto &i : esp.ingredients)
        {
            if (i->get_name() == "Water")
                ingredients.push_back(new Water{i->get_units()});
            else if (i->get_name() == "MilkFoam")
                ingredients.push_back(new MilkFoam{i->get_units()});
            else if (i->get_name() == "Sugar")
                ingredients.push_back(new Sugar{i->get_units()});
            else if (i->get_name() == "Chocolate")
                ingredients.push_back(new Chocolate{i->get_units()});
            else if (i->get_name() == "Cookie")
                ingredients.push_back(new Cookie{i->get_units()});
            else if (i->get_name() == "Espresso")
                ingredients.push_back(new Espresso{i->get_units()});
            else if (i->get_name() == "Milk")
                ingredients.push_back(new Milk{i->get_units()});
            else if (i->get_name() == "Cinnamon")
                ingredients.push_back(new Cinnamon{i->get_units()});
        }
    }
    std::cout << price() << "gg" << std::endl;
}
// void EspressoBased::brew(){}