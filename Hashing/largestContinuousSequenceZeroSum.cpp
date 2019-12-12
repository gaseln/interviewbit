// Largest Continuous Sequence Zero Sum
#include <iostream>
#include <vector>
#include <map>

std::vector<int> lszero(std::vector<int>& A) {

    std::vector<int> vec = A;
    for (unsigned int i = 0; i < vec.size() - 1; ++i) {
        vec[i + 1] += vec[i];
    }
    std::map<int, unsigned int> num_to_pos;
    unsigned int sec_pos = UINT_MAX;
    int current_max_length = 0, current_length;
    num_to_pos[0] = 0;

    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (num_to_pos.find(vec[i]) == num_to_pos.end()) {
            num_to_pos[vec[i]] = i + 1;
        } else {
            current_length = i - num_to_pos[vec[i]] + 1;
            if (current_length > current_max_length) {current_max_length = current_length; sec_pos = i + 1;}
        }
    }

    if (sec_pos == UINT_MAX) return {};

    return  std::vector<int>(A.begin() + num_to_pos[vec[sec_pos - 1]], A.begin() + sec_pos);
}

int main() {
    std::vector<int> vec = {1, 2, -3, 3};
    auto res = lszero(vec);
    for (auto& el : res) {
        std::cout << el << " ";
    }
}