// Combination Sum II
#include <iostream>
#include <vector>

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    if (target < 0) {
        return {};
    }

    std::vector<std::vector<int>> res, intermidiate_res;
    std::vector<int> candidates_copy, to_add_group;
    int to_add, count;

    while (!candidates.empty()) {
        to_add = candidates.back();
        count = 0;
        while (!candidates.empty() && candidates.back() == to_add) {candidates.pop_back(); count++;}
        candidates_copy = candidates;
        to_add_group = {};
        while (count--) {
            to_add_group.push_back(to_add);
            intermidiate_res = combinationSum2(candidates_copy, target - to_add);
            for (auto& el : intermidiate_res) {
                el.insert(el.end(), to_add_group.begin(), to_add_group.end());
            }
            res.insert(res.end(), intermidiate_res.begin(), intermidiate_res.end());
        }
    }

    if (!target) {res.push_back({});}

    std::sort(res.begin(), res.end());

    return res;
}

int main() {
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    auto res = combinationSum2(candidates, 8);
    for (auto& el : res) {
        for (auto& elem : el) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}