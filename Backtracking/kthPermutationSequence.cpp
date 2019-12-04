// kth Permutation Sequence (partially correct answer)

#include <vector>
#include <iostream>
#include <string>

std::string getPermutation(int n, int k) {
    auto k_ = (unsigned int) k;
    unsigned int factorial = 1;

    unsigned int i;

    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    std::vector<std::string> vec;
    vec.reserve(n);
    for (i = 1; i <= n; ++i) {
        vec.emplace_back(std::to_string(i));
    }

    std::string result;

    while (n) {
        factorial /= n;
        i =  (k_ - 1) / factorial + 1;
        result += vec[i - 1];
        vec.erase(vec.begin() + i - 1);
        k_ -= (i - 1) * factorial;
        n--;
    }

    return result;
}

int main() {
    auto res = getPermutation(3, 3);
    std::cout << res;
}