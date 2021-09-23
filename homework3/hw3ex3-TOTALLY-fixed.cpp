#include <iostream>
#include <functional>
#include <vector>

int calculate(double x1, double x2, std::function<double(double, double)> n){
    std::cout << (n)(x1, x2) << std::endl;
    return 0;
}


int main(){
    double x1 = 8.44; double x2 = 2;
std::vector<std::function<double(double, double)>> n = {[](double x1, double x2){return x1 + x2;}, [](double x1, double x2){return x1 / x2;}};
    for(int i = 0; i < std:: size (n); i++){
        calculate (x1, x2, n[i]);
    }
    
}