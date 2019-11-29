// Palindrome Partitioning
#include <iostream>
#include <vector>
#include <string>

bool isPalindrome(const std::string& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

std::vector<std::vector<std::string>> partition(std::string s) {
    if (s.empty()) {
        return {{}};
    }

    std::vector<std::vector<std::string>> result;
    std::vector<std::vector<std::string>> res_tmp;
    std::string curr_el;
    for (int i = 0; i < s.size(); ++i) {
        curr_el += s[i];
        if (isPalindrome(curr_el)) {
            res_tmp = partition(s.substr(i+1, std::string::npos));
            for (auto& el : res_tmp) {
                el.insert(el.begin(), curr_el);
            }
            result.insert(result.end(), res_tmp.begin(), res_tmp.end());
        }
    }

    return result;
}

int main() {
    std::string A = "aab";
    auto res = partition(A);
    for (auto& str : res) {
        std::cout << "[";
        for (auto& word : str) {
            std::cout << word << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}