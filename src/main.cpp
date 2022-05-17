#include <iostream>
#include <gtest/gtest.h>
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
#include "cappuccino.h"
#include "mocha.h"

int main(int argc, char **argv)
{
    if (0) // make false to run unit-tests
    {
        Espresso x{5}, z{10};
        int r{5};
        Espresso *p{new Espresso{x}};
        std::string y{typeid(x).name()};
        switch (r)
        {
        case 4:
            std::cout << "hk" << std::endl;
            break;
        default: // Cinnamon
            std::cout << "hk" << std::endl;
            break;
        }
        // debug section
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}