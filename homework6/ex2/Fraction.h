#ifndef INC_2_CPP_FRACTION_H
#define INC_2_CPP_FRACTION_H
#include <iostream>
using namespace std;

class Fraction{
private:
    int num; unsigned int den;
public:
    explicit Fraction(int a = 0, unsigned int b = 0): num(a), den(b) {}

    Fraction(const Fraction& src): num(src.num), den(src.den){}

    int get_numerator()  const {
        return num;
    }
    unsigned int get_denominator() const {
        return den;
    }
    int gcd(int a, int b) {}
    void Reduce(){}
    Fraction& operator=(const Fraction& src ){}
    Fraction operator++(int); //перегрузка постфиксного
    Fraction operator--(int); //перегрузка ппостфиксного
    Fraction& operator++();//перегрузка префиксного
    Fraction& operator--();//перегрузка префиксного
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
    friend bool operator>=(const Fraction &f1, const Fraction &f2){};
    friend bool operator<=(const Fraction &f1, const Fraction &f2){};
    friend bool operator==(const Fraction &f1, const Fraction &f2){};
};
Fraction operator+(const Fraction &f1, const Fraction &f2){}
Fraction operator-(const Fraction &f1, const Fraction &f2){}
Fraction operator*(const Fraction &f1, const Fraction &f2){}
Fraction operator/(const Fraction &f1, const Fraction &f2){}
bool operator<(const Fraction &f1, const Fraction &f2){}
bool operator>(const Fraction &f1, const Fraction &f2){}
bool operator>=(const Fraction &f1, const Fraction &f2){}
bool operator<=(const Fraction &f1, const Fraction &f2){}
bool operator==(const Fraction &f1, const Fraction &f2){}
ostream& operator<<(ostream& ostr, const Fraction& src){}
istream& operator>>(istream& in, Fraction& f){}
#endif //INC_2_CPP_FRACTION_H
