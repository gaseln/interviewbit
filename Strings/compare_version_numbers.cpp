#include <iostream>
#include <string>
#include <cstdlib>

void helper(std::string& version, std::string& str_num, size_t& end, int& num) {
    end = version.find('.');
    str_num = version.substr(0, end);
    version = version.substr(end + 1, std::string::npos);
    num = std::stoi(str_num, nullptr, 10);
}

int compareVersion(std::string version1, std::string version2) {
    int num1, num2;
    std::string str_num1, str_num2;
    size_t end1 , end2;
    version1 += '.';
    version2 += '.';
    while (!version1.empty() && !version2.empty()) {
        helper(version1, str_num1, end1, num1);
        helper(version2, str_num2, end2, num2);

        if (num1 != num2) {
            return -1 + 2 * (int) (num1 > num2);
        }

        str_num1 = str_num2 = "";
    }

    if (!version1.empty()) {
        while (!version1.empty()) {
            helper(version1, str_num1, end1, num1);
            if (num1 != 0) {
                return 1;
            }
        }

        return 0;
    }

    if (!version2.empty()) {
        while (!version2.empty()) {
            helper(version2, str_num2, end2, num2);
            if (num2 != 0) {
                return -1;
            }
        }

        return 0;
    }

    return 0;
}

int main() {
    std::string str1 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    std::string str2 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    std::cout << compareVersion(str1, str2);
    return 0;
}
