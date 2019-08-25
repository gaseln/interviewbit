#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool isDigit(char symbol) {
    return symbol - '0' >= 0 && symbol - '9' <= 0;
}

bool isSign(char symbol) {
    return symbol == '-' || symbol == '+';
}

int atoi(const std::string str) {
    std::istringstream str_stream(str);
    std::string first_word;
    str_stream >> first_word;
    std::istringstream first_word_stream(first_word);
    int sign_flag = 1;
    char symbol;
    int res = 0;
    int digit;

    if (!(isSign(first_word[0])|| isDigit(first_word[0]))) {
        return 0;
    }

    if (first_word[0] == '-') {
        sign_flag = -1;
        first_word_stream >> symbol;
    }

    if (first_word[0] == '+') {
        first_word_stream >> symbol;
    }

    while ((first_word_stream >> symbol)) {
        if (isDigit(symbol)) {
            digit = symbol - '0';

            if (sign_flag > 0) {
                if ((double) res >  ((double) (INT_MAX - digit) / 10)) {
                    return INT_MAX;
                }
            }

            if (sign_flag < 0) {
                if ((double) res < ((double) (INT_MIN + digit) / 10)) {
                    return INT_MIN;
                }
            }

            res *= 10;
            res = res + sign_flag * digit;
        } else {
            return res;
        }
    }

    return res;
}

int main() {
    std::string str = "  word 12002";
    std::cout << atoi(str);
    return 0;
}