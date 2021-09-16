#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr, help; int len, i, j, tmp;
    std::cout << "Enter array length" << "\n";
    std::cin >> len;
    std::cout << "Enter array" << "\n";
    for(i = 0; i < len; i++){
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    for (i = 1; i < len; i++){
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--){
            std::swap(arr[j + 1], arr[j]);
            std::swap(tmp, arr[j]);
        }
    }

    for(auto i : arr){
        std::cout << i << '\t';
    }
}