#include <iostream>
#include <vector>

int Search_Binary(std::vector<int> a, int l, int r, int key){
    int mid = 0;
    while(1){
        mid = (l + r) / 2;
        if (key < a[mid])
            r = mid - 1;
        else if (key > a[mid])
            l = mid + 1;
        else
            return mid;
        if (l > r)
            return -1;
    }
}

int main(){
    std::vector<int> arr; int id, len, key;
    std::cout << "Enter the length of your array" << std::endl;
    std::cin >> len;
    std::cout << "Enter the array" << std::endl;
    for(int i = 0; i < len; i++){
        std::cin >> id;
        arr.push_back(id);
    }

    std::cout << "Enter searched number:" << std::endl;
    std::cin >> key;

    id = Search_Binary(arr, 0, len, key);

    if (id >= 0)
        std::cout << "Your number is in the array";
    else
        std::cout << "There is no such number :(";
}