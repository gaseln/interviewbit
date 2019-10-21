#include <iostream>
#include <string>

std::string divideByTwo(std::string str) {

    std::string res;
    int next_digit;
    bool flag = false;
    for (int i = 0; i < str.length(); ++i) {

        if ((i == str.length() - 1) && ((str[i] - '0') % 2 == 1)) {
            return "<>";
        }

        next_digit = (str[i] - '0') / 2 + (int) flag * 5;
        res += char('0' + next_digit);
        flag = (str[i] - '0') % 2 == 1;
    }

    while (res[0] == '0') {
        res.erase(0, 1);
    }

    return res;
}

int power(std::string& str) {
    auto str_copy = str;

    while (true) {
        str_copy = divideByTwo(str_copy);

        if (str_copy == "<>") {
            return 0;
        }

        if (str_copy == "1") {
            return 1;
        }
    }

}

int main() {
    std::string num = "254";
    std::cout << power(num);
    return 0;
}