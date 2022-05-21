#include "espresso_based.h"
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

void EspressoBased::brew()
{
    // using namespace std::chrono_literals;
    std::string reset_position;
    ftxui::Element document = ftxui::border(ftxui::text("brewing ... ") | ftxui::bold | ftxui::color(ftxui::Color::Blue));
    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),       // Width
        ftxui::Dimension::Fit(document) // Height
    );
    ftxui::Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    double nt{};
    double n{};
    for (auto const &i : ingredients)
        nt += i->get_units();
    for (auto const &i : ingredients)
    {
        n += i->get_units();
        document = ftxui::window(ftxui::text((i->get_name() + " " + std::to_string(static_cast<int>(100 * n / nt)) + " % ")) | ftxui::color(ftxui::Color::Red), ftxui::border(ftxui::gauge(n / nt)));
        screen = ftxui::Screen::Create(
            ftxui::Dimension::Full(),       // Width
            ftxui::Dimension::Fit(document) // Height
        );
        ftxui::Render(screen, document);
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();
        std::this_thread::sleep_for(std::chrono::seconds((i->get_units())));
    }
    document = ftxui::border(ftxui::text("Complete !") | ftxui::bold | ftxui::color(ftxui::Color::Green));
    screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),       // Width
        ftxui::Dimension::Fit(document) // Height
    );
    ftxui::Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();
    std::this_thread::sleep_for(std::chrono::seconds(2));
}