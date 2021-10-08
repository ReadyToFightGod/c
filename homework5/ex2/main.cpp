#include "Vect.h"
#include <vector>
#include <iostream>

int main(){
    unsigned dim;
    std::cout << "Enter dimension: "; std::cin >> dim;
    std::vector<double> k(dim);
    std::cout << "Enter components: "; std::cin >> k;
    Vect a(dim, k);
    auto c = 5 * a;
    std::cout << c << std::endl;
}

