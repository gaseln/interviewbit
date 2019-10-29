//3 Sum Zero
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>>  res;
    int interm_ind, end;
    int candidate;
    int tmp;

    for (int begin = 0; begin + 2 < nums.size(); ++begin) {

        end = (int) nums.size() - 1;
        interm_ind = begin + 1;

        while (end > interm_ind) {
            candidate = nums[begin] + nums[interm_ind] + nums[end];


            if (candidate == 0) {
                res.push_back(std::vector<int>({nums[begin], nums[interm_ind], nums[end]}));
                tmp = nums[interm_ind];

                while ((tmp == nums[interm_ind]) && (interm_ind < end)) {
                    ++interm_ind;
                }
            }

            if (candidate < 0) {
                ++interm_ind;
            }

            if (candidate > 0){
                --end;
            }
        }

        while (begin + 1 < nums.size() && nums[begin + 1] == nums[begin]) ++begin;
    }

    return res;
}



int main() {
    std::vector<int> A = {-1, 0, 1, 2, -1, -4};
    auto a = threeSum(A);
    for (auto el : a) {
        for (auto num : el) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}