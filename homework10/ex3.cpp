#include <iostream>
int r = 0;
template<typename T, typename... Types>
int get_amount(T first_argument, Types... arguments) {
    r += sizeof(first_argument);
    if constexpr(sizeof...(arguments) > 0) {
        get_amount(arguments...);
    } else {return r;}
}

template <typename... Types>
auto sum(Types... arguments) {
    auto result = (sizeof(arguments) + ...);
    return result;
}

int main(){
    int n = get_amount(3, 10, 4.5, 33.5);
    int m = sum(3, 10, 4.5, 33.5);
    std::cout << n << ' ' << m;
}
