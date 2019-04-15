#include <iostream>
#include <vector>
#include <algorithm>

int findMinXor(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    int res = INT_MAX;
    int int_res = 0;
    for (int i = 0; i < A.size() - 1; ++i) {
        int_res = A[i]^A[i+1];
        if (int_res < res)
            res=int_res;
    }
    return res;
}

int main() {
    std::vector<int> A = {0, 2, 5, 7};
    std::cout << findMinXor(A)<< std::endl;
    return 0;
}