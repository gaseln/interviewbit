//Rain Water Trapped
#include <iostream>
#include <vector>

template<class T>
int trap_helper(T begin, T end) {

    if (begin == end) {
        return 0;
    }

    T it_begin = begin, it_end;
    int res = 0;
    do {
        it_end = it_begin + 1;
        while (*it_end < *it_begin) {
            ++it_end;
        }
        int curr_height = std::min(*it_begin, *it_end);
        ++it_begin;
        for (; it_begin != it_end; ++it_begin) {
            res += curr_height - *it_begin;
        }
    } while (it_end != end);

    return res;
}

int trap(const std::vector<int>& height) {
    int end = 0, max_ind = 0;

    if (height.empty()) {
        return 0;
    }

    while (end != height.size()) {
        if (height[max_ind] <= height[end]) max_ind = end;
        end++;
    }

    return trap_helper(height.begin(), height.begin() + max_ind) + trap_helper(height.rbegin(), height.rbegin() + end - max_ind - 1);
}

int main() {
    std::vector<int> A = {};
    std::cout << trap(A);
    return 0;
}