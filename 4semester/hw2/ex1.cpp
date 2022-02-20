#include <chrono>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std::chrono;

template <class T>
class Timer{
public:
    Timer(): start(steady_clock::now()){}
    ~Timer(){
        auto duration = duration_cast<T>(steady_clock::now()-start).count();
        std::cout << " total duration is: " << duration <<std::endl;
    }
private:
    steady_clock::time_point start;
};

int main(){
    std::array<int, 200000> a {}; std::vector<int> v {}; std::deque<int> d {};
    std::list<int> l {}; std::forward_list<int> fl {};
    for(auto i = 0; i < 100000; i++){
        a.front() = i; v.insert(v.begin(), i); d.push_front(i); l.push_front(i); fl.push_front(i);
    }
    for(auto i = 100000; i > 0; i--){
        a.front() = i; v.insert(v.begin(), i); d.push_front(i); l.push_front(i); fl.push_front(i);
    }
    {std::cout << "For array"; Timer<nanoseconds> ta; std::sort(a.begin(), a.end());}
    {std::cout << "For vector"; Timer<nanoseconds> tv; std::sort(v.begin(), v.end());}
    {std::cout << "For deque"; Timer<nanoseconds> td; std::sort(d.begin(), d.end());}
    {std::cout << "For list"; Timer<nanoseconds> tl; l.sort();}
    {std::cout << "For forward list"; Timer<nanoseconds> tfl; fl.sort();}
};