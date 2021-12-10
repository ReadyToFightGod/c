#include<iostream>

constexpr double e(int n){
    double res = 1;
    for (int i = 1; i <= n; ++i){
        res *= 2.71828;
    }
    return res;
}

int main(){
    constexpr auto res = e(4);
    std::cout << res << std::endl;
    return 0;
}