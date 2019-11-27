// Combination Sum
#include <iostream>
#include <vector>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    auto it = candidates.begin();
    while (it != candidates.end() && it + 1 != candidates.end()) {
        if (*it == *(it + 1)) {
            candidates.erase(it + 1);
        } else {
            it += 1;
        }
    }
    if (target < 0) {
        return {};
    }

    std::vector<std::vector<int>> res, intermidiate_res;
    std::vector<int> candidates_copy;
    int to_add;

    while (!candidates.empty()) {
        to_add = candidates.back();
        candidates_copy = candidates;
        intermidiate_res = combinationSum(candidates_copy, target - to_add);
        for (auto& el : intermidiate_res) {
            el.push_back(to_add);
        }
        res.insert(res.end(), intermidiate_res.begin(), intermidiate_res.end());
        candidates.pop_back();
    }

    if (!target) {res.push_back({});}

    std::sort(res.begin(), res.end());

    return res;
}

int main() {
    std::vector<int> candidates = {8, 10, 6, 11, 1, 16, 8};
    auto res = combinationSum(candidates, 28);
    for (auto& el : res) {
        for (auto& elem : el) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}