#include "Vect.h"

std::ostream& operator<<(std::ostream& out, const Vect& d){
    out << "Our vector: \n Dimension is " << d.get_dimension() << ", components are [";
    for(auto i=0u; i < d.get_dimension(); i++){
        std::cout << d.get_components()[i] << ", ";
    }
    std::cout << "]";
    return out;
}
std::istream& operator>>(std::istream& in,
                         std::vector<double>& v) {
    for (auto &elem: v) {
        std::cin >> elem;
    }
    return in;
}

void Vect::set_dimension(unsigned dimension){
    this->dimension = dimension;
    components.resize(dimension);
}
void Vect::set_components(std::vector<double>& components){
    this->components = components;
    dimension = components.size();
}

double module(Vect a){
    double result;
    for(int i = 0; i <= a.get_dimension(); i++){
        result += pow(a.get_components()[i], 2);
    }
    return sqrt(result);
}

Vect operator*(double lambda, Vect a){
    std::vector<double> r(a.get_dimension());
    for(int i = 0; i <= a.get_dimension(); i++){
        r[i] = a.get_components()[i] * lambda;
    }
    Vect result(a.get_dimension(), r);
    return result;
}

Vect operator*(Vect a, Vect b){
    std::vector<double> r(a.get_dimension());
    for(int i = 0; i <= a.get_dimension(); i++){
        r[i] = a.get_components()[i] * b.get_components()[i];
    }
    Vect result(a.get_dimension(), r);
    return result;
}

int main(){
    unsigned dim;
    std::cout << "Enter dimension: "; std::cin >> dim;
    std::vector<double> k(dim);
    std::cout << "Enter components: "; std::cin >> k;
    Vect a(dim, k);
    auto d = module(a);
    auto c = a * 5;
    std::cout << c << std::endl;
}

