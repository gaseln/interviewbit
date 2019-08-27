#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

bool isSign(char symbol) {
    return symbol == '-' || symbol == '+';
}

bool isDigit(char symbol) {
    return (symbol - '0' >= 0) && (symbol - '9' <= 0);
}

bool numbersOnly(std::string str) {

    if (str.empty()) {
        return true;
    }

    for (auto symbol : str) {
        if (!isDigit(symbol)) {
            return false;
        }
    }

    return true;
}

void signEraser(std::string& str) {
    if (!str.empty()) {
        if (isSign(str[0])) {
            str.erase(0, 1);
        }
    }
}

int isNumber(std::string str) {

    // reading the first word

    auto non_space_it = std::find_if(str.begin(), str.end(), [](char c) {return c != ' ';});

    if (non_space_it == str.end()) {
        return false;
    }

    auto el_it_second = std::find(non_space_it + 1, str.end(), ' ');

    std::string first_word(non_space_it, el_it_second);
    non_space_it = std::find_if(el_it_second, str.end(), [](char c) {return c != ' ';});

    // if another words exist, return false

    if (non_space_it != str.end()) {
        return false;
    }

    // find first symbol 'e' and split first_word into two parts

    auto e_it = std::find(first_word.begin(), first_word.end(), 'e');

    auto first_number = std::string(first_word.begin(), e_it);
    std::string second_number;

    if (e_it != first_word.end()) {
        second_number = std::string(e_it + 1, first_word.end());
    }

    // remove sign symbol if any exists

    signEraser(first_number);
    signEraser(second_number);

    // check numbers are not empty

    if (e_it != first_word.end() && (first_number.empty() || second_number.empty())) {
        return false;
    }

    if (first_number.empty() && second_number.empty()) {
        return false;
    }

    // find first decimal point and split first_number into two parts

    auto d_point_it = std::find(first_number.begin(), first_number.end(), '.');

    auto pre_point = std::string(first_number.begin(), d_point_it);
    std::string post_point;

    if (d_point_it != first_number.end()) {
        post_point = std::string(d_point_it + 1, first_number.end());
    }

    if (d_point_it != first_number.end() && post_point.empty()) {
        return false;
    }


    return numbersOnly(pre_point) && numbersOnly(post_point) && numbersOnly(second_number);
}

int main() {
    std::string str = "+      ";

    std::cout << isNumber(str);
    return 0;
}