// Combinations
#include <iostream>
#include <vector>

std::vector<std::vector<int>> combine(int n, int k) {

    if (n == 0 && k > 0) {
        return {};
    }

    if (k == 0) {
        return {{}};
    }


    auto res1 = combine(n - 1, k);
    auto res2 = combine(n - 1, k - 1);
    for (auto& el : res2) {
        el.push_back(n);
    }

    std::vector<std::vector<int>> result;
    result.reserve(res1.size() + res2.size());
    result.insert(result.end(), res1.begin(), res1.end());
    result.insert(result.end(), res2.begin(), res2.end());
    return result;
}

int main() {
    auto res = combine(4, 2);
    for (auto& el : res) {
        for (auto& sym : el) {
            std::cout << sym;
        }
        std::cout << std::endl;
    }
    return 0;
}