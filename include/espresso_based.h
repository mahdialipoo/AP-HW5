#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include <string>
#include <vector>
#include "sub_ingredients.h"
class EspressoBased
{
public:
    virtual std::string get_name() const = 0;
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient *> &get_ingredients();

    virtual ~EspressoBased();

protected:
    EspressoBased();
    EspressoBased(const EspressoBased &);
    void operator=(const EspressoBased &);

    std::vector<Ingredient *> ingredients;
    std::string name;
};

#endif // ESPRESSO_BASED_H