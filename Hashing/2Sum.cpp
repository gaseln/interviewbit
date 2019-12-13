// 2 Sum
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> h_table;
    int curr_el;
    for (int i = 0; i < nums.size(); ++i) {
        curr_el = target - nums[i];
        if (h_table.find(curr_el) == h_table.end()) {
            if (h_table.find(nums[i]) == h_table.end()) h_table[nums[i]] = i;
        } else {
            return {h_table[curr_el] + 1, i + 1};
        }
    }

    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    auto res = twoSum(nums, 9);
    for (auto& el : res) {
        std::cout << el << " ";
    }
}