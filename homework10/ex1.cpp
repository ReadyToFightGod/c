#include <iostream>
auto f = [](auto x){std::cout << x << std::endl; return x + 5; };
template<typename F>
void test(F f){
    auto a = f(32);
    auto b = f(32.77);
    auto c = f(2000000000ull);
    std::cout << a << ' ' << b << ' ' << c << std::endl;
}
int main(){
    test(f);
}

