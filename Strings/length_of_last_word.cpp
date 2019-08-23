#include <iostream>
#include <string>

int lengthOfLastWord(const std::string A) {
    std::string str = A;
    if (str.empty()) {
        return 0;
    }

    int j = (int) str.size() - 1;

    while ((str[j] == ' ') && (j >= 0)) {
        --j;
    }

    ++j;
    str = str.substr(0, j);

    if (str.empty()) {
        return 0;
    }

    int res = 0;
    for (auto el : str) {
        res++;
        if (el == ' ') {
            res = 0;
        }
    }

    return res;
}

int main() {
    std::string str = "a ";
    std::cout << lengthOfLastWord(str) << std::endl;
    return 0;
}