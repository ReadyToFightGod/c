#include "Fraction.h"

int main( ){
    Fraction f1, f2; char op;
    cout << "Enter first fraction (like a/b)\n"; cin >> f1;
    cout << "Enter operator (+, -, *, /, >, <) \n"; cin >> op;
    cout << "Enter second fraction (like a/b)\n"; cin >> f2;
    switch (op){
        case'+':
            cout << f1 << ' ' << op << ' ' << f2 << " = " << f1 + f2 << endl;
        case'-':
            cout << f1 << ' ' << op << ' ' << f2 << " = " << f1 - f2 << endl;
        case'*':
            cout << f1 << ' ' << op << ' ' << f2 << " = " << f1 * f2 << endl;
        case'/':
            cout << f1 << ' ' << op << ' ' << f2 << " = " << f1 / f2 << endl;
        case'<':
            cout << f1 << ' ' << op << ' ' << f2 << " = " << (f1 < f2) << endl;
        case'>':
            cout << f1 << ' ' << op << ' ' << f2 << " = " << (f1 > f2) << endl;
        default:
            cout << "Error!";
            break;
    }
    cout << "++" << f1 << ++f1 << "; "<< f1 << "++" << f1++ << endl;
    cout << "--" << f1 << --f1 << "; "<< f1 << "--" << f1-- << endl;
    cout << f1 " <= "<< f2 << " : " << f1 <= f2 << endl;
    cout << f1 " >= "<< f2 << " : " << f1 >= f2 << endl;
    cout << f1 " == "<< f2 << " : " << f1 == f2 << endl;
    cout << f1 << " in double is " << double(f1) << endl;
    cout << f2 << " in double is " << double(f2) << endl;
}
