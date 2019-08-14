#include <iostream>
#include <string>

std::string countAndSay(int n) {
    std::string str = "1";
    std::string tmp;

    int i = 1;

    while (i < n) {
        auto symbol = str[0];
        int n_symbol = 0;
        for (auto curr_symbol : str) {
            if (curr_symbol == symbol) {
                n_symbol++;
            } else {
                tmp += std::to_string(n_symbol) + symbol;
                symbol = curr_symbol;
                n_symbol = 1;
            }
        }
        tmp += std::to_string(n_symbol) + symbol;

        str = tmp;
        tmp = "";

        i++;
    }

    return str;
}

int main() {
    std::cout << countAndSay(3) << std::endl;
    return 0;
}
