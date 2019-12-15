// 4Sum
#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    auto n = (int) nums.size();

    std::sort(nums.begin(), nums.end());
    int k, l;
    std::vector<std::vector<int>> results;

    for (int i = 0; i < n - 3; ++i) {

        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        for (int j = i + 1; j < n - 2; ++j) {

            if (j > i + 1 && nums[j - 1] == nums[j]) {
                continue;
            }

            k = j + 1; l = n - 1;
            while (k < l) {
                if (nums[i] + nums[j] + nums[k] + nums[l] > target) {
                    do {l--;} while (l > j && nums[l] == nums[l + 1]);
                    continue;
                }

                if (nums[i] + nums[j] + nums[k] + nums[l] < target) {
                    do {k++;} while (k < n - 1 && nums[k - 1] == nums[k]);
                    continue;
                }

                if (nums[i] + nums[j] + nums[k] + nums[l]  == target) {
                    results.push_back({nums[i], nums[j], nums[k], nums[l]});
                    do {l--;} while (l > j && nums[l] == nums[l + 1]);
                    do {k++;} while (k < n - 1 && nums[k - 1] == nums[k]);
                }
            }
        }
    }

    return results;
}

int main() {
    std::vector<int> nums = {-5, -1, -1, 0, 2,2, 4};
    auto res = fourSum(nums, 3);
    for (auto& vec : res) {
        for (auto& el : vec) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}