#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string lcp;
    int min_size = INT_MAX;

    if (strs.empty()) {
        return "";
    }

    if (strs.size() == 1) {
        return strs[0];
    }

    for (auto& str : strs) {
        if (min_size > str.size()) {
            if (str.size() > INT_MAX) {
                std::cout << "Warning: string size is larger than INT_MAX" << std::endl;
            }
            min_size = str.size();
        }
    }

    if (min_size == 0) {
        return "";
    }

    int ind = 0;
    while (ind < min_size) {
        auto symbol = strs[0][ind];
        for (auto& str : strs) {
            if (str[ind] != symbol) {
                return lcp;
            }
        }
        lcp += symbol;
        ind++;
    }

    return lcp;
}



