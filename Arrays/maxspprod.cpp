#include <vector>
#include <algorithm>
#include <iostream>
//Haven't succeeded to solve
int maxSpecialProduct(std::vector<int> &A) {
    int n = A.size();
    std::vector<int> indices(n);
    int i = 0;
    std::generate(indices.begin(), indices.end(), [&i]{return i++;});
    std::sort(indices.begin(), indices.end(), [&A](int a, int b){return A[a] > A[b];});
    for (const auto& el:indices) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    if (n < 3) {
        return 0;
    }
    int max = std::max(indices[0], indices[1]), min = std::min(indices[0], indices[1]);
    int maxProd = 0;
    for (int i = 2; i < n; ++i) {
        if (A[indices[i] != A[indices[i-1]]]) {
            maxProd = std::max(maxProd, max * min);
        }
        min = std::min(min, indices[i]);
        max = std::max(max, indices[i]);
    }
    return maxProd;

}

int main() {
    std::vector<int> A = {5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9};
    std::cout <<maxSpecialProduct(A) << std::endl;
    return 0;
}