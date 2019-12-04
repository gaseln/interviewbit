// Letter Phone

#include <iostream>
#include <vector>
#include <string>
#include <map>

void helper(int& n, std::string& digits, std::map<char, std::string>& digits_to_chars, std::string& current, std::vector<std::string>& results) {
    if (n >= digits.size()) {
        results.emplace_back(current);
        return;
    }

    for (auto& character : digits_to_chars[digits[n] - '0']) {
        current += character;
        n += 1;
        helper(n, digits, digits_to_chars, current, results);
        n -= 1;
        current.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> results;

    unsigned long int memory = 1;
    for (const auto& digit : digits) {
        if (digit - '0' < 7 || digit - '0' == 8) {
            memory *= 3;
        } else {
            memory *= 4;
        }
    }

    results.reserve(memory);
    std::map<char, std::string> digits_to_chars = {
            {0, "0"},
            {1, "1"},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
    };

    int n = 0;
    std::string current;

    if (!digits.empty()) helper(n, digits, digits_to_chars, current, results);

    return results;
}

int main() {
    auto res = letterCombinations("");
    for (auto& el : res) {
        std::cout << el << " ";
    }
}