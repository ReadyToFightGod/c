#include <iostream>
#include <vector>

std::vector<int> merge_sort1(std::vector<int> A){
    if (std::size(A) == 1 || std::size(A) == 0){
        return A;
    }
    std::vector<int> L;
    std::vector<int> R;
    std::vector<int> C;
    for (int i = 0; i <= std::size(A)/2; i++){
        L.push_back(A[i]);
    }
    for (int i = std::size(A)/2; i <= std::size(A); i++){
        R.push_back(A[i]);
    }
    merge_sort1(L);
    merge_sort1(R);
    int m = 0;
    int n = 0;
    int k = 0;
    for (int i = 0; i < std::size(L) +std::size(R); i++){
        C.push_back(0);
    }
    while (n < std::size(L) && m < std::size(R)){
        if (L[n] <= R[m]){
            C[k] = L[n];
            ++n;
        }
        else{
            C[k] = R[m];
            ++m;
            ++k;
        }
    }
    while(n < std::size(L)) {
        C[k] = L[n];
        ++n;
        ++k;
    }
    while(m < std::size(R)) {
        C[k] = R[m];
        ++m;
        ++k;
    }
    for(int i = 0; i < std::size(A); i++){
        A[i] = C[i];
    }
    return A;
}

int main() {
    std::vector<int> M;
    std::vector<int> A = {7, -42, 5, 0,16,-8};
    M = merge_sort1(A);
    for(int i = 0; i < M.size(); i++){
        std::cout << "\n" << M[i] << "\n";
    }
    return 0;
}