#ifndef HW5EX2_CPP_VECT_H
#define HW5EX2_CPP_VECT_H
#include <iostream>
#include <vector>
#include <cmath>

class Vect{
private:
    unsigned dimension;
    std::vector<double> components;
public:
    Vect(unsigned new_dimension, const std::vector<double>& new_components): components(new_components), dimension(new_dimension){}

    const std::vector<double>& get_components() const {
        return components;
    }
    unsigned get_dimension() const {
        return dimension;
    }
    void set_dimension(unsigned dimension);
    void set_components(std::vector<double>& components);

    friend std::ostream& operator<<(std::ostream& out, const Vect& v);
    friend Vect operator*(double lambda, Vect a);
    friend Vect operator*(Vect a, double lambda);
    friend Vect operator*(Vect a, Vect b);
    friend double module(Vect a);
};
double module(Vect a){
    auto c = a * a; double result;
    for(int i = 0; i <= c.get_dimension(); i++){
        result += c.get_components()[i];
    }
    return sqrt(result);
}
#endif //HW5EX2_CPP_VECT_H
