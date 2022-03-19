#include <iostream>
#include <numeric>
#include <vector>
#include <thread>
#include <chrono>
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

template <typename Iterator, typename T>
void accumulate_wrapper(Iterator begin, Iterator end, T init, T& result) {
    result = std::accumulate(begin, end, init);
}

template <typename Iterator, typename T>
T parallel_accumulate(Iterator begin, Iterator end, T init, unsigned num_workers) {
    auto size = std::distance(begin, end);
    if (num_workers > std::thread::hardware_concurrency()){return 0;}
    if (size < num_workers * 4) {
        return std::accumulate(begin, end, init);
    }
    auto size_per_worker = size / num_workers;
    std::vector<std::thread> threads;
    std::vector<T> results(num_workers - 1);
    for(auto i = 0u; i < num_workers - 1; i++) {
        threads.push_back(std::thread(accumulate_wrapper<Iterator, T>,
                                      std::next(begin, i * size_per_worker),
                                      std::next(begin, (i + 1) * size_per_worker),
                                      0,
                                      std::ref(results[i])));
    }
    auto main_result = std::accumulate(
            std::next(begin, (num_workers - 1) * size_per_worker),
            end, init);
    for(auto& thread: threads) {
        thread.join();
    }
    return std::accumulate(std::begin(results),
                           std::end(results), main_result);
}

int main() {
    unsigned num_workers;
    std::cout << "How many threads do you want to have? " << std::endl;
    std::cin >> num_workers;
    std::vector<int> sequence(100);
    std::iota(std::begin(sequence), std::end(sequence), 0);
    {Timer<nanoseconds> t;
        std::cout << parallel_accumulate(std::begin(sequence),
                                         std::end(sequence), 0, num_workers) << std::endl;}
    std::cout << "If you have 0, try a smaller number of threads." << std::endl;
}

//оптимальное количество потоков - 3