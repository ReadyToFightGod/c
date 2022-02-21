#include <iostream>
#include <map>
#include <algorithm>
#include <chrono>
#include <random>

class Container{
private:
    std::map<std::string, int> cont;
public:
    Container(const std::map<std::string, int> &cont) : cont(cont) {}

    void typography(std::string s){
        for(auto it = cont.begin(); it != cont.end(); it++){
            if (it->first == s){
                std::cout << s << " : " << it->second << std::endl;
                return;
            }
        }
        std::cout << "Error" << std::endl;
    }

    void quick(std::string s){
        std::cout << s << " : " << cont.find(s)->second << std::endl;
    }

    void agency(){
        int e = cont.size(); auto k = 0;
        auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
        auto generator = std::mt19937_64(current_timestamp);
        auto distribution = std::uniform_int_distribution(0, e-1);
        int c = distribution(generator);
        for(auto it = cont.begin(); it != cont.end(); it++){
            if (c != k) {k++; continue;}
            else {
                std::cout << it->first << " : " << it->second << std::endl;
                return;
            }
        }
        return;
    }
};

int main() {
    Container s({{"Me",  1}, {"dude",  4104},
                  {"Niki", 588434}, {"nice",  42069},
                  {"Max",  2}, {"sEIGHTan", 666}});
    s.typography("Max");
    s.quick("sEIGHTan");
    s.agency();
};
