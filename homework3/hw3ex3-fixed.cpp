#include <iostream>
#include <functional>
#include <vector>

int calculate(double x1, double x2, std::vector<std::function<double(double, double)>> n){
    for(int i = 0; i <= std:: size (n); i++){
        std::cout << (n[i])(x1, x2) << std::endl;
    }
    return 0;
}


int main(){
    double x1 = 8.44; double x2 = 2;
std::vector<std::function<double(double, double)>> n = {[](double x1, double x2){return x1 + x2;}, [](double x1, double x2){return x1 / x2;}};
    calculate (x1, x2, n);
}