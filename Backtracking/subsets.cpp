//Subsets
#include <iostream>
#include <vector>

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    if (nums.empty()) {
        return {{}};
    }

    auto add = nums.back();
    nums.pop_back();
    auto res = subsets(nums);
    auto copy = res;
    for (auto& el : copy) {
        el.push_back(add);
    }
    std::vector<std::vector<int>> result;
    result.reserve(res.size() + copy.size());
    result.insert(result.end(), res.begin(), res.end());
    result.insert(result.end(), copy.begin(), copy.end());
    return result;
}

int main() {
    std::vector<int> A = {1, 2, 3};
    auto res = subsets(A);
    for (auto& el : res) {
        std::cout << "[ ";
        for (auto& sub_el : el) {
            std::cout << sub_el << " ";
        }
        std::cout << " ]" << std::endl;
    }
    return 0;
}