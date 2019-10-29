//Sort by color
#include <iostream>
#include <vector>

//incorrect solution
void sortColors_(std::vector<int>& nums) {
    std::vector<int> its(3);
    std::vector<bool> flags(3);

    flags[0] = (nums[0] == 0);
    its[0] = (flags[0]) ? 1 : 0;

    for (int ind = 1; ind < 3; ++ind) {
        flags[ind] = (nums[0] == ind);
        its[ind] = its[ind - 1];

        if (flags[ind]) {
            its[ind]++;
        }
    }

    if (nums.size() == 1) {
        return;
    }

    while (its[2] != nums.size()) {
        if (nums[its[2]] == 0) {
            flags[0] = true;
            nums[its[0]] = 0;
            ++its[0];

            if (flags[1]) {
                nums[its[1]] = 1;
            }

            ++its[1];

            if (flags[2]) {
                nums[its[2]] = 2;
            }
        }

        if (nums[its[2]] == 1) {
            flags[1] = true;
            nums[its[1]] = 1;
            ++its[1];

            if (flags[2]) {
                nums[its[2]] = 2;
            }
        }

        if (nums[its[2]] == 2) {
            flags[2] = true;
        }

        ++its[2];
    }
}

//correct straight-forward solution
void sortColors(std::vector<int>& nums) {
    std::vector<int> counts(3);
    for (auto el : nums) {
        counts[el]++;
    }
    int ind = 0;
    while (counts[0] > 0) {
        nums[ind] = 0;
        counts[0]--;
        ind++;
    }
    while (counts[1] > 0) {
        nums[ind] = 1;
        counts[1]--;
        ind++;
    }
    while (counts[2] > 0) {
        nums[ind] = 2;
        counts[2]--;
        ind++;
    }
}

int main() {
    std::vector<int> A = {0, 0, 0, 1, 0, 2, 2, 0, 1, 1, 0, 2, 2, 1, 1, 0, 0, 2, 1, 0, 1, 2, 0, 0, 0, 2, 1, 1, 0, 2, 1, 0, 2, 0, 0, 0, 2, 0, 2, 0, 1, 1, 0, 2, 2, 1, 2, 2, 1, 2, 0, 1, 2, 2, 1, 0, 1, 1, 0, 0, 1, 1, 2, 0, 1, 2, 2, 0, 2, 2, 1, 0, 1, 0, 0, 0, 2, 2, 0, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 2, 2, 0, 1, 0, 2, 1, 0, 1, 0, 0, 0, 2, 1, 1, 1, 0, 1, 0, 0, 2, 0, 0, 0, 1, 2, 0, 2, 2, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 2, 1, 2, 2, 0, 2, 1, 1, 0, 2, 2, 1, 1, 0, 2, 1, 2, 0, 2, 2, 0, 1, 0, 2, 0, 2, 0, 1, 2, 0, 2, 2, 1, 2, 0, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 1, 0, 0, 2, 2, 2, 1, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0, 1, 0, 2, 2, 2, 0, 0, 0, 0, 1, 2, 0, 1, 1, 1, 0, 1, 1, 2, 2, 1, 0, 0, 1, 2, 0, 1, 1, 0, 2, 2, 1, 0, 2, 1, 0, 0, 2, 1, 1, 1, 1, 2, 0, 1, 0, 2, 0, 1, 2, 2, 0, 2, 0, 0, 2, 1, 0, 1, 2, 1, 1, 2, 2, 1, 0, 2, 2, 0, 0, 2, 2, 2, 1, 2, 1, 2, 2, 1, 0, 2, 0, 0, 0, 0, 0, 2, 2, 2, 1, 0, 0, 2, 2, 1, 2, 0, 1, 2, 0, 2, 1, 2, 0, 1, 0, 2, 0, 2, 2, 1, 0, 1, 0, 0, 1, 0, 1, 2, 1, 1, 2, 1, 0, 2, 2, 1, 0, 1, 1, 0, 1, 2, 1, 2, 1, 2, 0, 0, 0, 2, 0, 0, 1, 0, 2, 2, 2, 0, 1, 1, 0, 2, 2, 0, 2, 2, 1, 2, 1, 1, 1, 0, 1, 0, 1, 0, 2, 0, 2, 2, 2, 2, 0, 2, 0, 2, 1, 2, 2, 0, 1, 1, 0, 1, 2, 2, 2, 1, 2, 0, 2, 1, 2, 1, 0, 1, 0, 2, 2, 0, 1, 0, 2, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 2, 2, 0, 2, 1, 2, 0, 1, 2, 0, 0, 2, 2, 2, 2, 0, 0, 1, 1, 2, 0, 0, 0, 0, 1, 2, 2, 2, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 2, 2, 1, 0, 1, 1, 2, 1, 2, 2, 0, 1, 0, 0, 1};
    sortColors(A);
    for (auto el : A) {
        std::cout << el << " ";
    }
    return 0;
}