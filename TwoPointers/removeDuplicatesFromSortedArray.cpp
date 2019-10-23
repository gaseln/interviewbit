//Remove duplicates from sorted array
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int count = 0;

    if (nums.size() == 1) {
        return 1;
    }

    for (int ind = 1; ind < nums.size(); ++ind) {
        if (nums[ind] == nums[ind - 1]) {
            count++;
        } else {
            nums[ind - count] = nums[ind];
        }
    }

    return (int) nums.size() - count;
}

int main() {
    std::vector<int> A = {1, 1, 2};
    std::cout << removeDuplicates(A);
    return 0;
}