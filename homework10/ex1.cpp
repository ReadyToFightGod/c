#include <iostream>
auto f = [](auto... x){return (x + ...); };
template<typename F, typename... Types>
void test(F f, Types... x){
    std::cout << f(x...);
}
int main(){
    test(f, 0, 8, 9);
}

