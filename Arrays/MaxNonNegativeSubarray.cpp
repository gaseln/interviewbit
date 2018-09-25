#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> maxset(std::vector<int> &A) {
    auto begin = A.begin();
    auto end  = A.begin();
    auto begin_best = begin;
    auto end_best = end;
    unsigned long long current_sum = 0, max_sum = 0;
    bool init_flag = false;
    std::size_t max_length = 0, current_length = 0;
    while (end != A.end()) {
        if (*end >= 0) {
            current_sum += *end;
            init_flag = true;
        }
        if ((*end < 0 or std::next(end) == A.end()) and init_flag) {
            if ((current_sum >= max_sum) or (max_sum == 0)) {
                current_length = (std::next(end) == A.end()) ? A.end() - begin : end - begin;
                if (((current_length > max_length) and (current_sum == max_sum)) or (current_sum > max_sum)) {
                    begin_best = begin;
                    end_best = (std::next(end) == A.end()) ? A.end() : end;
                    max_sum = current_sum;
                    max_length = current_length;
                }
            }
            current_sum = 0;
            if (next(end) != A.end()) {
                begin = next(end);
            }
        }
        ++end;
    }
    return {begin_best, end_best};
}

int main() {
    std::vector<int> A = {10, 10, -1, 11, 9, 0};
    auto B = maxset(A);
    for (const auto& el : B) {
        std::cout << el << " ";
    }
    return 0;
}
