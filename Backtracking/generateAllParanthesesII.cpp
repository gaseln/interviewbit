// Generate All Parantheses

#include <iostream>
#include <vector>
#include <string>

std::vector<unsigned long long> Catalan_number(int n) {
    std::vector<unsigned long long> cat_nums;
    cat_nums.reserve(n + 1);
    cat_nums.push_back(1);
    int j;
    for (int i = 1; i <= n; ++i) {
        cat_nums.push_back(0);
        for (j = 0; j < i; ++j) {
            cat_nums[i] += cat_nums[j] * cat_nums[i - 1 - j];
        }
    }

    return cat_nums;
}


std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::vector<std::string>> all_subproblems;
    all_subproblems.reserve(n + 1);
    auto memory_arrangement = Catalan_number(n);
    all_subproblems.push_back({""});

    for (int i = 1; i <= n; ++i) {
        all_subproblems.emplace_back();
        all_subproblems[i].reserve(memory_arrangement[i]);

        for (int j = i - 1; j >= 0; --j) {

            for (auto& el : all_subproblems[j]) {
                for (auto& el_2 : all_subproblems[i - j - 1]) {
                    all_subproblems[i].emplace_back('(' + el + ')' + el_2);
                }
            }
        }
    }

//    std::sort(all_subproblems.back().begin(), all_subproblems.back().end());

    return all_subproblems.back();
}

int main() {
    auto res = generateParenthesis(3);
    for (auto& vec : res) {
        for (auto& el : vec) {
            std::cout << el;
        }
        std::cout << std::endl;
    }
}