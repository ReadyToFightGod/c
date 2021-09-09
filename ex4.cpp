#include<iostream>
int main() {
    int x, y;
    std::cout << "Enter x: " << "\n";
    std::cin >> x;
    std::cout << "Enter y: " << "\n";
    std::cin >> y;
    x = x + y;
    y = y - x;     //y=-x and x=x+y
    y = -y;
    x = x - y;
    std::cout <<"Now x is " << x << "\n";
    std::cout << "Now y is " << y;
    return 0;
}