#include <iostream>
#include <vector>

int main(){
    int n;
    std::cout << "Enter dimension number" << "\n";
    std::cin >> n;

    std::cout << "Enter vector coordinates" << "\n";
    std::vector<double> coordinates;
    for(int i = 0; i < n; i ++){
        double x;
        std::cin >> x;
        coordinates.push_back(x);
    }

    std::vector<std::vector<double>> M(2);
    for(auto& line : M){
        double y;
        std::cout << "Enter matrix line" << "\n";
        for(int i = 0; i < n; i++){
            std::cin >> y;
            line.push_back(y);
        }
    }

    std::vector<double> new_coordinates;
    for(auto& line : M){
        double x1 = 0;
        for(int i = 0; i < n; i++){
            x1 += line[i] * coordinates[i];
        }
        new_coordinates.push_back(x1);
    }

    for(auto& i : new_coordinates){
        std::cout << i << "\t";
    }
}
