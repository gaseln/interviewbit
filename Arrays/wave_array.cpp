#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> wave(std::vector<int>& A) {
    std::sort(A.begin(), A.end());
    for (size_t i = 0; i < A.size() / 2; ++i) {
        std::swap(A[2*i], A[2*i + 1]);
    }
    return A;
}

int main() {
    std::vector<int> A = {};
    A = wave(A);
    for (const auto& el: A) {
        std::cout << el << " ";
    }
    return 0;
}
