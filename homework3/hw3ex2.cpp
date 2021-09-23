#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> L, std::vector<int> R){
    std::vector<int> C;
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

std::vector<int> merge_sort(std::vector<int>& A){
    if (A.size() == 1){
        return A;
    }
    else{
        std::vector<int> L, R;
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
    std::vector<int> A = {7, -42, 5, 0,16,-8};
    std::vector<int> M = merge_sort(A);
    for (auto  i : M){
        std::cout << i << std::endl;
    }
}
