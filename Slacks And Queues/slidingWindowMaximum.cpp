// Sliding Window Maximum
#include <iostream>
#include <vector>

std::vector<int> slidingMaximum(const std::vector<int>& nums, int k) {

    if (nums.empty()) {
        return {};
    }

    std::vector<int> stack;

    //initialization
    for (int i = k - 1; i >= 0; --i) if (stack.empty() || nums[stack.back()] < nums[i]) stack.push_back(i);
    std::reverse(stack.begin(), stack.end());

    // modifying vector
    int start = 0;
    std::vector<int> res = {nums[stack[start]]};

    for (int i = k; i < nums.size(); ++i) {
        if (stack[start] < i - k  + 1) start++;
        while (stack.size() > start && nums[stack.back()] <= nums[i]) stack.pop_back();
        stack.push_back(i);
        res.push_back(nums[stack[start]]);
    }

    return res;
}

int main() {
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = slidingMaximum(nums, 4);
    for (auto el : res) {
        std::cout << el << " ";
    }
    return 0;
}