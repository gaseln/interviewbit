#include <iostream>
#include <string>
#include <map>
#include <set>

int romanToInt(std::string roman) {
    std::map<std::string, int> double_roman_to_int = {
            {"IX", 9},
            {"IV", 4},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}};
    std::map<std::string, int> unary_roman_to_int = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000}};
    int res(0);
    std::set<std::string> double_romans = {"IX", "IV", "XL", "XC", "CD", "CM"};
    std::string lookup;

    auto it = roman.begin();
    for (; it != roman.end(); ++it) {
        if (it + 1 != roman.end()) {
            lookup = std::string(it, it + 2);
            if (double_romans.find(lookup) != double_romans.end()) {
                res += double_roman_to_int[lookup];
                ++it;
                continue;
            }
        }

        lookup = std::string(it, it + 1);
        res += unary_roman_to_int[lookup];
    }

    return res;
}

int main() {
    std::string roman = "MCMXCIV";
    std::cout << romanToInt(roman);
    return 0;
}