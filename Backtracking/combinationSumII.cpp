// Combination Sum II
#include <iostream>
#include <vector>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    if (target < 0) {
        return {};
    }

    std::vector<std::vector<int>> res, intermediate_res;
    std::vector<int> candidates_copy, to_add_group;
    int to_add, count;

    while (!candidates.empty()) {
        to_add = candidates.back();
        count = 0;
        to_add_group = {};
        while (!candidates.empty() && candidates.back() == to_add) {candidates.pop_back(); count++; to_add_group.push_back(to_add);}
//        std::cout << candidates.size() << std::endl;
        while (count) {
            candidates_copy = candidates;
            intermediate_res = combinationSum(candidates_copy, target - count * to_add);
            count--;
            for (auto& el : intermediate_res) {
                el.insert(el.end(), to_add_group.begin(), to_add_group.end());
            }
            to_add_group.pop_back();
            res.insert(res.end(), intermediate_res.begin(), intermediate_res.end());
        }
    }

    if (!target) {res.push_back({});}

    std::sort(res.begin(), res.end());

    return res;
}

int main() {
    std::vector<int> candidates = {1, 1, 2, 2, 2};
    auto res = combinationSum(candidates, 6);
    for (auto& el : res) {
        for (auto& elem : el) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}