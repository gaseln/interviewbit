// Diffk II
#include <iostream>
#include <vector>
#include <unordered_set>

int diffPossible(const std::vector<int>& nums, int target) {
    std::unordered_set<int> hash_table;
    for (const auto& num : nums) {
        if (hash_table.find(num + target) != hash_table.end()) {
            return 1;
        }

        if (hash_table.find(num - target) != hash_table.end()) {
            return 1;
        }

        hash_table.insert(num);
    }

    return 0;
}

int main() {
    std::vector<int> nums = {1, 2, 2};
    std::cout << diffPossible(nums, 2);
}