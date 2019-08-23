#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned int> substring_preprocessing(std::string substring) {
    std::vector<unsigned int> pi(substring.size());
    unsigned int i, j;
    i = 1;
    j = 0;
    pi[0] = 0;
    while (i < pi.size()) {
        if (substring[i] == substring[j]) {
            pi[i++] = j++ + 1;
        } else {
            if (j == 0) {
                pi[i++] = 0;
            } else {
                j = pi[j - 1];
            }
        }
    }

    return pi;
}

int knuth_morris_pratt_algorithm(const std::string str, const std::string substr) {

    if (substr.empty() || str.empty()) {
        return -1;
    }

    auto pi = substring_preprocessing(substr);
    unsigned int str_iterator, substr_iterator;
    str_iterator = substr_iterator = 0;
    while (str_iterator < str.size()) {
        if (str[str_iterator] == substr[substr_iterator]) {
            ++str_iterator;
            ++substr_iterator;
            if (substr_iterator == substr.size()) {
                return (int) (str_iterator - substr.size());
            }
        } else if (substr_iterator > 0) {
            substr_iterator = pi[substr_iterator - 1];
        } else {
            ++str_iterator;
        }
    }

    return -1;
}

int strStr(const std::string A, const std::string B) {
    return knuth_morris_pratt_algorithm(A, B);
}

int main() {
    std::string str = "abbaabbab";
    std::string substr = "bab";
    auto pi = substring_preprocessing(substr);
    for (auto el : pi) {
        std::cout << el;
    }
    std::cout << std::endl;
    std::cout << strStr(str, substr);
    return 0;
}