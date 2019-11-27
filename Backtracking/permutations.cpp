// Permutations
#include <iostream>
#include <vector>

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> nums_copy;
    int a;
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        nums_copy = nums;
        a = nums[i];
        nums_copy.erase(nums_copy.begin() + i);
        auto res = permute(nums_copy);
        for (auto& el : res) {
            el.insert(el.begin(), a);
            result.push_back(el);
        }
    }

    if (nums.empty()) {result.push_back({});}
    return result;
}

int main() {
    std::vector<int> A = {1, 2, 3};
    auto res = permute(A);
    for (auto& vec : res) {
        for (auto& elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}