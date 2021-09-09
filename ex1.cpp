#include <iostream>
#include <iomanip>

int main() {
    std::cin >> std::boolalpha;
    std::string name;
    int price, temperature;
    bool hasCashback;

    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";

    std::cin >> std::boolalpha >> hasCashback;
    std::cout << "Maximum storing temperature: ";
    std::cin >> std::dec >> temperature;

    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    std::cout << name << "\n";
    std::cout << std::setw(16) << std::left << std::setfill('.') << "Price:" <<
    std::setw(8) << std::right << std::setfill('0') << std::uppercase << std::hex << price << '\n';

    std::cout << "Has cash-back:" << std::setfill('.') << std::setw(10) <<
    std::right << std::right << std::boolalpha << hasCashback << "\n";
    std::cout << "Max temperature" << std::setfill('.') << std::setw(9) << std::right <<
    std::right << std::showpos << std::dec << temperature << std::endl;
    return 0;
}

