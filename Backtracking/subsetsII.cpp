// Subsets II
#include <iostream>
#include <vector>

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    if (nums.empty()) {
        return {{}};
    }
    std::sort(nums.begin(), nums.end());
    auto add = nums[0];
    nums.erase(nums.begin());
    int count = 1;
    while (!nums.empty() && nums[0] == add) {nums.erase(nums.begin()); count++;}
    auto res = subsetsWithDup(nums);
    std::vector<std::vector<int>> result;
    res.erase(res.begin());

    std::vector<int> last = {};
    for (unsigned int i = 0; i <= count; ++i) {
        result.push_back(last);
        last.push_back(add);
    }


    for (unsigned int i = 0; i <= count; ++i) {
        last.pop_back();
        for (auto el : res) {
            el.insert(el.begin(), last.begin(), last.end());
            result.push_back(el);
        }
    }

    return result;
}

int main() {
    std::vector<int> A = {4, 5};
    auto res = subsetsWithDup(A);
    for (auto& el : res) {
        std::cout << "[ ";
        for (auto& sub_el : el) {
            std::cout << sub_el << " ";
        }
        std::cout << " ]" << std::endl;
    }
    return 0;
}