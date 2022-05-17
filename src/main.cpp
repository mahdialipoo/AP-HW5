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
        Cappuccino cappuccino;
        cappuccino.add_side_item(new Water{1});
        Cappuccino equal;
        equal.add_side_item(new Sugar{1});
        equal = cappuccino;
        std::cout << equal.price() << std::endl;
        std::cout << cappuccino.price() << std::endl;
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