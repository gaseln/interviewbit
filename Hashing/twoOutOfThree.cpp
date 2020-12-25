#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<int> twoOutOfThree(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
    std::unordered_map<int, char> intEl; // intersecting elements
    std::vector<int> final;

    for (auto& num: A) {
        if (intEl.find(num) == intEl.end()) {
            intEl[num] = 1;
        }
    }
    
    for (auto& num: B) {
        if (intEl.find(num) == intEl.end()) {
            intEl[num] = 2;
        } else if (intEl[num] == 1) {
            intEl[num] = -1;
            final.emplace_back(num);
        }
    }
    
    for (auto& num: C) {
        if (intEl.find(num) != intEl.end() && intEl[num] != -1) {
            intEl[num] = -1;
            final.emplace_back(num);
        }
    }

    std::sort(final.begin(), final.end());
    return final;
}

int main() {
    std::vector<int> A = {56, 56, 34, 34, 72, 71};
    std::vector<int> B = {56, 56, 34, 34, 72, 71};
    std::vector<int> C = {56, 56, 34, 34, 72, 71};
    auto res = twoOutOfThree(A, B, C);
    for (auto& num: res) {
        std::cout << num << ' ';
    }
    return 0;
}