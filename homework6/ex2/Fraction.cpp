#include "Fraction.h"
Fraction::Fraction& operator=(const Fraction& src ){
    num = src.num;
    den = src.den;
    return *this;
}
Fraction::int gcd(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
Fraction::void Reduce(){
    int Gcd = gcd(num, den);
    num /= Gcd;
    den /= Gcd;
}
Fraction operator+(const Fraction &f1, const Fraction &f2){
    auto res = Fraction(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den);
    res.Reduce();
    return res;
}
Fraction operator-(const Fraction &f1, const Fraction &f2){
    auto res = Fraction(f1.num * f2.den - f1.den * f2.num, f1.den * f2.den);
    res.Reduce();
    return res;
}
Fraction operator*(const Fraction &f1, const Fraction &f2){
    auto res = Fraction(f1.num * f2.num, f1.den * f2.den);
    res.Reduce();
    return res;
}
Fraction operator/(const Fraction &f1, const Fraction &f2){
    auto res = Fraction(f1.num / f2.num, f1.den / f2.den);
    res.Reduce();
    return res;
}
//перегрузка префиксного
Fraction& Fraction::operator++(){
    this->num += den;
    (*this).Reduce();
    return *this;
}
//перегрузка префиксного
Fraction& Fraction::operator--(){
    this->num -= den;
    (*this).Reduce();
    return *this;
}
//перегрузка постфиксного
Fraction Fraction::operator++(int){
    Fraction tmp(num, den);
    ++(*this);
    return tmp;
}
//перегрузка постфикстного
Fraction Fraction::operator--(int){
    Fraction tmp(num, den);
    --(*this);
    return tmp;
}
bool operator<(const Fraction &f1, const Fraction &f2){
    return f1.num * f2.den < f1.den * f2.num;
}
bool operator>(const Fraction &f1, const Fraction &f2){
    return f1.num * f2.den > f1.den * f2.num;
}
bool operator==(const Fraction &f1, const Fraction &f2){
    return f1.num * f2.den == f1.den * f2.num;
}
bool operator<=(const Fraction &f1, const Fraction &f2){
    return f1.num * f2.den <= f1.den * f2.num;
}
bool operator>=(const Fraction &f1, const Fraction &f2){
    return f1.num * f2.den >= f1.den * f2.num;
}
ostream& operator<<(ostream& ostr, const Fraction& src){
    return cout << src.get_numerator() << "/" << src.get_denominator();
}
istream& operator>>(istream& in, Fraction& f){
    int na, nb = 1; char c;
    in >> na;
    in >> c;
    if (c == '/') in >> nb;
    if(nb != 0){f = Fraction(na,nb);}
    else{cout << "Error! Division by zero is undefined!";}
    return in;
}
