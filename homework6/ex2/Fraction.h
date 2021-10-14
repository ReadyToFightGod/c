#ifndef INC_2_CPP_FRACTION_H
#define INC_2_CPP_FRACTION_H
#include <iostream>
using namespace std;

class Fraction{
private:
    signed int num; int den;
public:
    explicit Fraction(signed int a = 0, int b = 0): num(a), den(b) {}

    Fraction(const Fraction& src): num(src.num), den(src.den){}

    signed int get_numerator()  const {
        return num;
    }
    int get_denominator() const {
        return den;
    }
    int gcd(int a, int b) {}
    void Reduce(){}
    Fraction& operator=(const Fraction& src ){}
    //перегрузка постфиксного
//    Fraction operator++(){
//        this->num += den;
//        return *this;
//    }
//    Fraction operator--(){
//        this->num -= den;
//        return *this;
//    }
    explicit operator double() const {
        return double(num)/double(den);
    }
    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& ostr, const Fraction& src);
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);
    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator>(const Fraction &f1, const Fraction &f2);
    friend Fraction operator++(const Fraction &f1);
    friend Fraction operator--(const Fraction &f1);
};
Fraction operator+(const Fraction &f1, const Fraction &f2){}
Fraction operator-(const Fraction &f1, const Fraction &f2){}
Fraction operator*(const Fraction &f1, const Fraction &f2){}
Fraction operator/(const Fraction &f1, const Fraction &f2){}
//перегрузка префиксного
Fraction operator++(const Fraction &f1){}
//перегрузка префиксного
Fraction operator--(const Fraction &f1){}
bool operator<(const Fraction &f1, const Fraction &f2){};
bool operator>(const Fraction &f1, const Fraction &f2){};
ostream& operator<<(ostream& ostr, const Fraction& src){}
istream& operator>>(istream& in, Fraction& f){}
#endif //INC_2_CPP_FRACTION_H
