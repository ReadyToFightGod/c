#include <iostream>
//Реализуйте функцию, которая предоставляет количество дней в указанном пользователем месяце,
// используя именованные константы перечисления с областью видимости и оператор switch-case-default.

enum class Months {
    JANUARY = 1, FEBRUARY, MARCH, APRIL,
    MAY, JUNE, JULY, AUGUST, SEPTEMBER,
    OCTOBER, NOVEMBER, DECEMBER
};

int main() {
    std::cout << "Input month: 1 for January, ..." << std::endl;
    Months month;
    int month_number;
    std::cin >> month_number;
    month = static_cast<Months>(month_number);
    switch (month){
        case Months::JANUARY:
            std::cout << "There are 31 days in January!" << std::endl;
            break;
        case Months::FEBRUARY:
            std::cout << "There are 28 days in February!" << std::endl;
            break;
        case Months::MARCH:
            std::cout << "There are 31 days in March!" << std::endl;
            break;
        case Months::APRIL:
            std::cout << "There are 30 days in April" << std::endl;
            break;
        case Months::MAY:
            std::cout << "There are 31 days in May!" << std::endl;
            break;
        case Months::JUNE:
            std::cout << "There are 30 days in June!" << std::endl;
            break;
        case Months::JULY:
            std::cout << "There are 31 days in July!" << std::endl;
            break;
        case Months::AUGUST:
            std::cout << "There are 31 days in August!" << std::endl;
            break;
        case Months::SEPTEMBER:
            std::cout << "There are 30 days in September!" << std::endl;
            break;
        case Months::OCTOBER:
            std::cout << "There are 31 days in October!" << std::endl;
            break;
        case Months::NOVEMBER:
            std::cout << "There are 30 days in November!" << std::endl;
            break;
        case Months::DECEMBER:
            std::cout << "There are 31 days in December" << std::endl;
            break;
        default:
            std::cout << "Such month does not exist!" << std::endl;
    }
}