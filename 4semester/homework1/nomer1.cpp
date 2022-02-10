#include <chrono>
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std::chrono;

template <class T>
class Timer{
public:
    Timer(): start(steady_clock::now()){}
    ~Timer(){
        if (pause != 1){delay += duration_cast<T>(steady_clock::now() - stop).count();}
        auto duration = duration_cast<T>(steady_clock::now()-start).count()-delay;
        std::cout << "Total duration is: " << duration <<std::endl;
    }
    void Clock_stop(){
        if (pause == 1){
            stop = steady_clock::now();
            pause = 0;
        }
        else{std::cout << "The clock is already paused."<<std::endl;}
    }
    void Resume(){
        if (pause != 1) {
            delay += duration_cast<T>(steady_clock::now() - stop).count();
            pause = 1;
        }
        else{std::cout << "Please pause the clock first." << std::endl;}
    }
private:
    steady_clock::time_point start;
    steady_clock::time_point stop;
    int delay = 0; int pause = 1;
};

int main() {
    auto result = 0.;
    {
        Timer<milliseconds> t;
        int n=10000;
        for(auto i = 0u; i < 1'000'000u; i++) {
            result += sin(i) * cos(i);}
        t.Clock_stop();
        for(auto i = 0u; i < 1'000'000u; i++) {
            result += sin(i) * cos(i);}
        t.Resume();
        std::cout << "Just for longer time" << std::endl;
        t.Resume();
    }
    std::cout << "Result is  " << result;
}