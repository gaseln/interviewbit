//Subsets
#include <iostream>
#include <vector>

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    if (nums.empty()) {
        return {{}};
    }

    auto add = nums[0];
    nums.erase(nums.begin());
    auto res = subsets(nums);
    auto copy = res;
    for (auto& el : copy) {
        el.insert(el.begin(), add);
    }
    res.erase(res.begin());
    std::vector<std::vector<int>> result;
    result.reserve(res.size() + copy.size());
    result.push_back({});
    result.insert(result.end(), copy.begin(), copy.end());
    result.insert(result.end(), res.begin(), res.end());
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