#include <iostream>
#include <cmath>

class Energy{
private:
    double value;
    static double erg; static double ev;
public:
    Energy(double new_value): value(new_value) {}
    double get_value_erg() const{
        return value * erg;
    }
    double get_value_ev() const{
        return value * ev;
    }
    void set_value_erg(double value){
        this->value = value / erg;
    }
    void set_value_ev(double value){
        this->value = value / ev;
    }
};

double Energy::erg = pow(10, 7);
double Energy::ev = 6.24 * pow(10, 18);

int main(){
    double v;
    std::cout << "Enter energy value in Joules: "; std::cin >> v;
    Energy energy(v);
    std::cout << "Energy converted to erg is: " << energy.get_value_erg() << std::endl;
    std::cout << "Energy converted to ev is: " << energy.get_value_ev() << std::endl;
}