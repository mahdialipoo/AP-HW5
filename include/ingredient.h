#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <vector>
class Ingredient
{
public:
    double get_price_unit() { return price_unit; }
    size_t get_units() { return units; }
    virtual std::string get_name() = 0;

    double price() { return price_unit * units; }

protected:
    Ingredient(double _price_unit, size_t _units) : price_unit{_price_unit}, units{_units} {}

    double price_unit;
    size_t units;
    std::string name;
};

#endif // INGREDIENT_H