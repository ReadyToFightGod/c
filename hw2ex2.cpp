#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string line; char sep; int pos; std::vector<std::string> vec;

    std::cout << "Enter the string" << "\n";
    std::cin >> line;
    std::cout << "Enter the separator" << "\n";
    std::cin >> sep;

    int len = line.length();
    for(int i = 0; i <= len; i++){
        pos = line.find(sep);
        vec.push_back(line.substr(0, pos));
        if(pos == len - 1)
            line = line.erase(0,pos);
        else
            line = line.erase(0,pos + 1);
        len = line.length();
    }
    vec.push_back(line);
    for(auto i : vec){
        std::cout << i << " ";
    }
}
