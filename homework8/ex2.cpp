#include <iostream>

class NoSuchDayException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: there is no such day in the month";
    }
};
class NoSuchMonthException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: there is no such month in the year";
    }
};

class Date{
public:
    Date(int d, int m, int y){
        year = y;
        if (m < 1 || m > 12){
            throw NoSuchMonthException();
        }
        else{
            month = m;
        }
        if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (0 < d) && (d < 32)){
            day = d;
        }
        else if((m == 4 || m == 6 || m == 9 || m == 11) && (0 < d) && (d < 31)){
            day = d;
        }
        else if((m == 2)&& (0 < d) && (d < 29) && (y % 4 || (y % 100 == 0 && y % 400))){ //nevesokosniy god
            day = d;
        }
        else if((m == 2)&& (0 < d) && (d < 30) && (y % 4 == 0 || y % 400 == 0)){ //vesokosniy god
            day = d;
        }
        else{
            throw NoSuchDayException();
        }
    }
    int get_year() const {
        return year;
    }
    int get_month() const {
        return month;
    }
    int get_day() const {
        return day;
    }
    friend Date operator<(const Date& d1, const Date& d2);
    friend std::ostream& operator<<(std::ostream& out, const Date& d);
private:
    int year, month, day;
};

Date operator<(const Date& d1, const Date& d2){
    if (d1.year < d2.year){
        return d2;
    }
    if (d1.year == d2.year && d1.month < d2.month){
        return d2;
    }
    if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day){
        return d2;
    }
}

std::ostream& operator<<(std::ostream& out, const Date& d){
    std::cout << d.day << "/" << d.month << "/" << d.year << std::endl;
    return out;
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    std::cout << "Please enter day: " << std::endl; std::cin >> d1;
    std::cout << "Please enter month: " << std::endl; std::cin >> m1;
    std::cout << "Please enter year: " << std::endl; std::cin >> y1;
    std::cout << "Please enter day: " << std::endl; std::cin >> d2;
    std::cout << "Please enter month: " << std::endl; std::cin >> m2;
    std::cout << "Please enter year: " << std::endl; std::cin >> y2;
    try{
    Date date1(d1, m1, y1);
    Date date2(d2, m2, y2);
    std::cout << "Date 1: " << date1 << "Date 2: " << date2 << "" << std::endl;
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}