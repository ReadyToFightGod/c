#include <functional>
#include <vector>
#include <iostream>
int main(){
    std::vector<int> s = {2, 6, 8,0, 15, 31, -5};
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
    });
    for(int i = 0; i < 7; i++){
        std::cout << s[i] << std::endl;
    }
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a < b;
    });
    for(int i = 0; i < 7; i++){
        std::cout << s[i] << std::endl;
    }
}


