//Remove element from array
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int count = 0;

    for (int ind = 0; ind < nums.size(); ++ind) {
        if (nums[ind] == val) {
            count++;
        } else {
            nums[ind - count] = nums[ind];
        }
    }

    return (int) nums.size() - count;
};

int main() {
    std::vector<int> A = {0,1,2,2,3,0,4,2};
    int val = 2;
    std::cout << removeElement(A, val);
    return 0;
}