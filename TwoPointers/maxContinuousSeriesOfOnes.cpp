//Max Continuous Series of 1s
#include <iostream>
#include <vector>

std::vector<int> maxone(std::vector<int>& nums, int M) {
    int begin = 0, end = 0, n_zeros = 0, begin_star = 0, end_star = 0, length_star = 0, current_length = 0;

    while (begin!= nums.size()) {

        while (end!= nums.size() && (n_zeros != M || nums[end] == 1)) {
            n_zeros += (nums[end] == 0);

            ++end;

            current_length = end - begin;

            if (current_length > length_star) {
                length_star = current_length;
                begin_star = begin;
                end_star = end;
            }

        }

        ++begin;
        n_zeros -= (nums[begin - 1] == 0);
    }

    std::vector<int> res;

    for (; begin_star < end_star; ++begin_star) {
        res.push_back(begin_star);
    }

    return res;
}

int main() {
    std::vector<int> A = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
    int M = 1;
    auto B = maxone(A, M);
    for (auto el : B) {
        std::cout << el << " ";
    }
    return 0;
}
