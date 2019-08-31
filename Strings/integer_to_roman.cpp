#include <string>
#include <iostream>

void helperIntToRoman(int& num, std::string& res, int value, std::string abbr) {
    while (num / value >= 1) {
        res += abbr;
        num -= value;
    }
}

std::string intToRoman(int num) {
    std::string res;

    helperIntToRoman(num, res, 1000, "M");
    helperIntToRoman(num, res, 900, "CM");
    helperIntToRoman(num, res, 500, "D");
    helperIntToRoman(num, res, 400, "CD");
    helperIntToRoman(num, res, 100, "C");
    helperIntToRoman(num, res, 90, "XC");
    helperIntToRoman(num, res, 50, "L");
    helperIntToRoman(num, res, 40, "XL");
    helperIntToRoman(num, res, 10, "X");
    helperIntToRoman(num, res, 9, "IX");
    helperIntToRoman(num, res, 5, "V");
    helperIntToRoman(num, res, 4, "IV");
    helperIntToRoman(num, res, 1, "I");

    return res;
}

int main() {
    int num = 59;
    std::cout << intToRoman(num);
    return 0;
}