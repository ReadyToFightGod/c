#include <iostream>
#include <vector>
#include <cmath>

struct Vect{
    unsigned dim;
    std::vector<double> components;
};

Vect operator*(Vect a, double lambda){
    Vect result;
    for(int i = 0; i <= a.dim; i++){
        result.components[i] = a.components[i] * lambda;
    }
    return result;
}

Vect operator*(double lambda, Vect a){
    Vect result;
    for(int i = 0; i <= a.dim; i++){
        result.components[i] = a.components[i] * lambda;
    }
    return result;
}

Vect operator+(Vect a, Vect b){
    Vect result;
    for(int i = 0; i <= a.dim; i++){
        result.components[i] = a.components[i] + b.components[i];
    }
    return result;
}

Vect operator-(Vect a, Vect b) {
    Vect result;
    for (int i = 0; i <= a.dim; i++){
        result.components[i] = a.components[i] - b.components[i];
    }
    return result;
}

Vect operator*(Vect a, Vect b){
    Vect result;
    for(int i = 0; i <= a.dim; i++){
        result.components[i] = a.components[i] * b.components[i];
    }
    return result;
}

Vect operator-(Vect a){
    Vect result;
    for(int i = 0; i <= a.dim; i++){
        result.components[i] = -a.components[i];
    }
    return result;
}

double module(Vect a){
    double result;
    for(int i = 0; i <= a.dim; i++){
        result += a.components[i] * a.components[i];
    }
    return sqrt(result);
}

std::istream& operator>>(std::istream& in,
                         std::vector<double>& v){
    for (auto& elem: v){
        std::cin >> elem;
    }
    return in;
}

std::ostream& operator<<(std::ostream& ostr,
                         const std::vector<double>& nums){
    ostr << "[";
    for (auto i = 0u; i < nums.size(); i++){
        ostr << nums[i];
        if (i != nums.size() - 1) ostr << ", ";
    }
    ostr << "]";
    return ostr;
}

int main(){
    unsigned dim;
    std::cout << "Enter number of dimensions: "; std::cin >> dim;
    std::vector<double> n1(dim), n2(dim);
    std::cout << "Enter vector a: "; std::cin >> n1;
    std::cout << "Enter vector b: "; std::cin >> n2;
    Vect b{dim, n2}; Vect a{dim, n1};
    auto c = -a;
    std::cout << c.components << std::endl;
}