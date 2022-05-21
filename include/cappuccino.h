#ifndef CAPPUCCINO
#define CAPPUCCINO
#include <vector>
#include <string>
#include "espresso_based.h"
class Cappuccino : public EspressoBased
{
public:
    Cappuccino();
    Cappuccino(const Cappuccino &);
    ~Cappuccino();
    void operator=(const Cappuccino &);
    // void brew();
    virtual std::string get_name() const;
    virtual double price();

    void add_side_item(Ingredient *);
    std::vector<Ingredient *> &get_side_items();

private:
    std::vector<Ingredient *> side_items;
};
#endif // CAPPUCCINO