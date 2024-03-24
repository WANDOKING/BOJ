#include <iostream>

int main(void)
{
    int burger1;
    int burger2;
    int burger3;
    int drink1;
    int drink2;

    std::cin >> burger1 >> burger2 >> burger3 >> drink1 >> drink2;

    int minBurger = std::min(burger1, std::min(burger2, burger3));
    int minDrink = std::min(drink1, drink2);

    std::cout << minBurger + minDrink - 50;
}
