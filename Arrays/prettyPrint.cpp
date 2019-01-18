#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> prettyPrint(int A) {
    int n = 2 * A - 1;
    std::vector<std::vector<int>> res(n);
    std::vector<int> filler(n);
    std::fill(filler.begin(), filler.end(), A);
    res[0] = filler;
    for (int i = 1; i < n; ++i) {
        if (i < (n + 1)/2) {
            for (int j = i; j <= n-1-i; ++j) {
                filler[j] = A - i;
            }
            res[i] = filler;
        } else {
            res[i] = res[n - 1 - i];
        }
    }
    return res;
}

int main() {
    auto vec = prettyPrint(1);
    for (auto line : vec) {
        for (auto el: line) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
