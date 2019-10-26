#include <iostream>
#include <vector>

int diffPossible(std::vector<int>& nums, int target) {
    int begin = 0;
    int end = 1;
    int candidate;

    while (end < nums.size()) {
        candidate = nums[begin] + target - nums[end];

        if (candidate == 0) {
            return 1;
        } else if ((candidate > 0) || (begin + 1 == end)) {
            ++end;
        } else {
            ++begin;
        }
    }

    return 0;
}

int main() {
    std::vector<int> A = {1, 2, 3};
    std::cout << diffPossible(A, 0);
    return 0;
}
