#include <vector>
#include <iostream>

void nextPermutation(std::vector<int>& A) {
    int i = A.size() - 1;
    while (i > 0) {
        if (A[i] <= A[i - 1]) {
            --i;
        } else {
            break;
        }
    }
    if (i != 0) {
        int border_ind = i;
        for (int j = A.size() - 1; j > i - 1; --j) {
            if ((A[j] < A[border_ind]) and (A[j] > A[i-1])) {
                border_ind = j;
            }
        }
        std::swap(A[border_ind], A[i-1]);
    }
    std::sort(A.begin() + i, A.end());
}

int main() {
    std::vector<int> A = {5, 1, 1};
    nextPermutation(A);
    for (const auto& el : A) {
        std::cout << el << " ";
    }
    return 0;
}
