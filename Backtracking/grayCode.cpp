// Gray Code
#include <iostream>
#include <vector>

void grayCodeHelper(int add, int local_n, std::vector<int>& result) {

    if (local_n == 0) {
        result.push_back(add);
        return;
    }

    auto it = result.size();
    grayCodeHelper(0, local_n - 1, result);
    auto n_end = result.size();
    int local_add = 1 << (local_n - 1);

    for (auto i = it; i < n_end; ++i) {
        result[n_end + it - 1 - i] += add;
        result.push_back(result[n_end + it - 1 - i] + local_add);
    }
}

std::vector<int> grayCode(int n) {
    std::vector<int> result;
    result.reserve(1 << n);
    grayCodeHelper(0, n, result);
    return result;
}

int main() {
    auto res = grayCode(1);
    for (auto& el : res) {
        std::cout << el << " ";
    }
    return 0;
}