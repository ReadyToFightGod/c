#include<iostream>
#include<cmath>
int main() {
    double A, B, C, D, X1, X2;
    std::cout << "enter a =";
    std::cin >> A;
    std::cout << "enter b =";
    std::cin >> B;
    std::cout << "enter c =";
    std::cin >> C;
    if (A != 0)
    {
        D = pow(B, 2) - 4 * A * C;
        if (D >= 0)
        {
            X1 = (-B + sqrt(D) )/ (2 * A);
            X2 = (-B - sqrt(D) )/ (2 * A);
            if (X1 == X2)
            {
                std::cout << "x = " << X1;
            }
            else
            {
                std::cout << "x1 = " << X1 <<"\n"<<"x2 = "  << X2;
            }
        }


    }
    if (A == 0)
    {
        if (B != 0)
        {
            std::cout << "This is a linear equation :) " << "\n";
            std::cout << " x = " << -C / B;
        }
        else
        {
            std::cout << "It's bot even an equation.";
        }
    }
    return 0;
}