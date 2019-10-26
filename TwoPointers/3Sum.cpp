//3 Sum
#include <vector>
#include <iostream>
#include <algorithm>

int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int interm_ind, end;
    int closest = nums[0] + nums[1] + nums[2];
    int candidate;

    for (int begin = 0; begin + 2 < nums.size(); ++begin) {
        end = (int) nums.size() - 1;
        interm_ind = begin + 1;

        while (end > interm_ind) {
            candidate = nums[begin] + nums[interm_ind] + nums[end];

            if (abs(closest - target) > abs(candidate - target)) {
                closest = candidate;
            }

            if (candidate == target) {
                return target;
            }

            if (candidate < target) {
                ++interm_ind;
            } else {
                --end;
            }
        }
    }

    return closest;
}

int main() {
    std::vector<int> A = {-1, 2, 1, -4};
    std::cout << threeSumClosest(A, 1);
    return 0;
}