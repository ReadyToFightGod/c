#include <iostream>
#include<cmath>
int main() {
    const double pi = 3.14;
    double a;
    std::int16_t number;
    std::cout
            << "What do you want to convert? Please, enter the number " << "\n"
            << "1)electric charge" << "\n" << "2)electric flux" << "\n" << "3)magnetic B field" << "\n";
    std::cin >> number;

    switch (number)
    {
        case 1:
            std::cout << "Please,enter the value: ";
            std::cin >> a;
            std::cout << a / 10 << ", Franklin";
            break;
        case 2:
            std::cout << "Please,enter the value: ";
            std::cin >> a;
            std::cout << a / 10 * 4 * pi << ", StatC";
            break;
        case 3:
            std::cout << "Please,enter the value: ";
            std::cin >> a;
            std::cout << a * pow(10, 4) << ", G";
            break;
    }
    return 0;
}