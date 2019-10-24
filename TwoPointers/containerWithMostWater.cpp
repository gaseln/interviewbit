//Container with most water
#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int num) {
    int size = (int) nums.size();

//    for (auto el : nums) {
//        std::cout << el << " ";
//    }
//    std::cout << std::endl;

    if (nums[size - 1] <= num) {
        return size - 1;
    }

    if (nums[0] >= num) {
        return 0;
    }

    int begin = 0;
    int end = size - 1;
    int interm;

    while (begin != end) {
        interm = (begin + end) / 2;

        if (nums[interm] < num) {
            begin = interm + 1;
        }

        if (nums[interm] >= num) {
            end = interm;
        }
    }

    return begin;
}

int maxAreaLR(std::vector<int>& height) {
    std::vector<int> maxs;
    std::vector<int> maxs_ind;
    maxs.push_back(height[0]);
    maxs_ind.push_back(0);

    int max = 0;
    for (int ind = 1; ind < height.size(); ++ind) {
        auto max_ind = binarySearch(maxs, height[ind]);
        max = std::max(max, (ind - maxs_ind[max_ind]) * std::min(height[ind], maxs[max_ind]));
        
        if (height[ind] > maxs[maxs.size() - 1]) {
            maxs.push_back(height[ind]);
            maxs_ind.push_back(ind);
        }
    }

    return max;
}

int maxArea(std::vector<int>& height) {
    auto max_1 = maxAreaLR(height);
    std::reverse(height.begin(), height.end());
    auto max_2 = maxAreaLR(height);
    return std::max(max_1, max_2);
}

int main() {
    std::vector<int> height = {1, 2};
    std::cout << maxArea(height);
    return 0;
}