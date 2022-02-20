//Разработайте контейнер для хранения телефонного справочника. Согласно контракту, необходимо обеспечить:
//Доступ к записям, отсортированным по фамилии человека (для городской типографии).
//Произвольный доступ к записям справочника (для рекламного агентства).
//Быстрый поиск по фамилии человека (для регулярных пользователей).

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

void typography(std::string s, std::map<std::string, int> m){
    for(auto it = m.begin(); it != m.end(); it++){
        if (it->first == s){
            std::cout << s << " : " << it->second << std::endl;
            return;
        }
    }
    std::cout << "Error" << std::endl;
}

void quick(std::string s, std::map<std::string, int> m){
    std::cout << s << " : " << m.find(s)->second << std::endl;
}

void agency(std::map<std::string,int> m){
    int e = m.size(); auto k = 0;
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(0, e-1);
    int c = distribution(generator);
    for(auto it = m.begin(); it != m.end(); it++){
        if (c != k) {k++; continue;}
        else {
            std::cout << it->first << " : " << it->second << std::endl;
            return;
        }
    }
    return;
}
int main() {
    std::map<std::string, int> s{{"Me",  1}, {"dude",  4104},
                                 {"Niki", 588434}, {"nice",  42069},
                                 {"Max",  2}, {"sEIGHTan", 666}};
    typography("Max", s);
    quick("sEIGHTan", s);
    agency(s);
};