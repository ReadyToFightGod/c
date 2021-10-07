#ifndef HW5EX2_CPP_VECT_H
#define HW5EX2_CPP_VECT_H
#include <iostream>
#include <vector>

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
};
#endif //HW5EX2_CPP_VECT_H
