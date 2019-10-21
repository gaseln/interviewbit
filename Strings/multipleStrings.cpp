#include <iostream>
#include <string>

std::string strByDigit(std::string num, char digit) {
    std::string res;
    int add = 0;
    int tmp;
    for (int i = (int) num.length() - 1; i >= 0; --i) {
        tmp = (num[i] - '0') * (digit - '0') + add;
        add = tmp / 10;
        res += char('0' + tmp % 10);
    }

    if (add != 0) {
        res += char('0' + add);
    }

    std::reverse(res.begin(), res.end());

    return res;
}

std::string AddTwoNums(std::string num1, std::string num2) {
    if (num1.length() > num2.length()) {
        return AddTwoNums(num2, num1);
    }

    int add = 0, tmp;
    std::string res;
    auto it_1 = num1.rbegin();
    for (auto it = num2.rbegin(); it != num2.rend(); ++it) {

        tmp = (*it -'0') + add;

        tmp += (it_1 == num1.rend()) ? 0 : (*it_1 - '0');

        add = tmp / 10;
        res += char('0' + tmp % 10);

        if (it_1 != num1.rend()) {
            ++it_1;
        }
    }

    if (add != 0) {
        res += char('0' + add);
    }

    std::reverse(res.begin(), res.end());

    return res;
}

std::string processInput(std::string num) {
    auto it = std::find_if(num.begin(), num.end(), [](char c) { return c != '0';});
    std::string res = {it, num.end()};
    if (res.empty()) {
        res += "0";
    }

    return res;
}

std::string multiply(std::string num1, std::string num2) {

    num1 = processInput(num1);
    num2 = processInput(num2);

    if (num1.length() < num2.length()) {
        return multiply(num2, num1);
    }

    if (num2 == "0") {
        return "0";
    }

    std::string res = "0", tmp;
    std::string additional_zeros ="";
    auto it = num2.rbegin();
    for (; it != num2.rend(); ++it) {
        tmp = strByDigit(num1, *it);
        tmp += additional_zeros;
        res = AddTwoNums(res, tmp);
        additional_zeros += "0";
    }

    return res;
}

int main() {
    std::string num = "665";
    std::string num2 = "00";
    std::cout << multiply(num, num2);
    return 0;
}