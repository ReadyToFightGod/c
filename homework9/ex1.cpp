#include <iostream>
#include <vector>

template<typename T>
std::vector<T> merge(std::vector<T> L, std::vector<T> R){
    std::vector<T> C;
    int j = 0, k = 0;
    bool a = true, b = true;
    for (int i = 0; i < L.size() + R.size(); i++){
        if (((L[j] < R[k]) && a) || !b){
            C.push_back(L[j]);
            if (j == L.size() - 1) {a = false;}
            else{ j ++;}
        }
        else if ((L[j] >= R[k] && a) ||  b){
            C.push_back(R[k]);
            if (k == R.size() - 1) {b = false;}
            else{k ++;}
        }
    }
    return C;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T>& A){
    if (A.size() == 1){
        return A;
    }
    else{
        std::vector<T> L, R;
        for(int i = 0; i < A.size(); i++){
            if (i < A.size() / 2){
                L.push_back(A[i]);
            }
            else{
                R.push_back(A[i]);}
        }
        L = merge_sort(L);
        R = merge_sort(R);
        return merge(L, R);
    }
}

int main(){
    std::vector<std::string> A = {"a", "def", "bc"};
    std::vector<std::string> M = merge_sort(A);
    for (auto  i : M){
        std::cout << i << std::endl;
    }
}
