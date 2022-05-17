#ifndef MOCHA_H
#define MOCHA_H
#include <vector>
#include <string>
#include "espresso_based.h"
class Mocha : public EspressoBased
{
public:
    Mocha();
    Mocha(const Mocha &);
    ~Mocha();
    void operator=(const Mocha &);

    virtual std::string get_name() const;
    virtual double price();

    void add_side_item(Ingredient *);
    std::vector<Ingredient *> &get_side_items();

private:
    std::vector<Ingredient *> side_items;
};
#endif // MOCHA_H