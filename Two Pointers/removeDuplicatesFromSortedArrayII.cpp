//Remove duplicates from sorted array II
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int count = 0;

    if (nums.size() < 3) {
        return (int) nums.size();
    }

    int start_ind;
    bool upd_flag = false;

    for (int ind = 2; ind < nums.size(); ++ind) {
        if ((nums[ind] == nums[ind - 1]) && (nums[ind - 1] == nums[ind - 2])) {
            count++;

            if (count == 1) {
                start_ind = ind;
            }

            if (count == 2) {
                for (; start_ind < ind - 1; ++start_ind) {
                    nums[start_ind] = nums[start_ind + 1];
                }

                upd_flag = true;
            }

        } else if (count > 1) {
            nums[ind - count] = nums[ind];
        }
    }

    if (!upd_flag) {
        for (; start_ind < nums.size() - 1; ++start_ind) {
            nums[start_ind] = nums[start_ind + 1];
        }
    }

    return (int) nums.size() - count;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2,  2, 2, 3, 3};
    auto length = removeDuplicates(nums);
    std::cout << length << std::endl;
    int count = 0;
    for (auto el : nums) {
        if (count == length) {
            break;
        }
        std:: cout << el << " ";
        count++;
    }
    return 0;
}