#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


int solve(std::string str) {
    const std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    const int round_const = 10003;
    const int str_length = (int) str.size();
    const int max_input_length = (int) 1e6; // maximum length of input data

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return std::tolower(c);});

    if (INT_MAX < max_input_length) {
        std::cout << "Error: INT_MAX is less than maximum potential length of input data" << std::endl;
        return -1;
    }

    int res = 0;

    for (int i = 0; i < str_length; ++i) {
        if (std::find(vowels.begin(), vowels.end(), str[i]) != vowels.end()) {
            res += str_length - i;
            res %= round_const;
        }
    }

    return res;
}

int main() {
    std::cout << solve("AbeC") << std::endl;
    return 0;
}