#include <iostream>
#include <functional>
#include <vector>

int main(){
    double x1 = 8.44; double x2 = 2;
    std::function<double(double, double)> summa = [](double x1, double x2){
        return x1 + x2;
    };
    std::function<double(double, double)> div = [](double x1, double x2){
        return x1 / x2;
    };
    std::vector<std::function<double(double, double)>> calculate;
    calculate.push_back(summa);
    calculate.push_back(div);
    for(int i = 0; i < 2; i++) {
        std::cout << (calculate[i])(x1, x2) << std::endl;
    }
}
