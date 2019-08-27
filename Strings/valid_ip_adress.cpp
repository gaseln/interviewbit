#include <iostream>
#include <string>

#define Neither "Neither"
#define IPv4 "IPv4"
#define IPv6 "IPv6"

// https://leetcode.com/problems/validate-ip-address/

bool isDecimalDigit(char symbol) {
    return (symbol - '0' >= 0) && (symbol - '9' <= 0);
}

bool isHexadecimalDigit(char symbol) {
    return isDecimalDigit(symbol) || (symbol - 'a' >=0 && symbol - 'f' <= 0);
}

bool checkIPv4Validity(std::string::iterator& it_begin, std::string::iterator& it_end) {

    int num = 0;

    if (it_end == it_begin) {
        return false;
    }

    if (*it_begin == '0' && (it_end - it_begin > 1)) {
        return false;
    }

    for (; it_begin != it_end; ++it_begin) {
        if (isDecimalDigit(*it_begin)) {
            num *= 10;
            num += (*it_begin - '0');
        } else {
            return false;
        }

        if (num > 255) {
            return false;
        }
    }

    return true;
}

bool checkIPv6Validity(std::string::iterator& it_begin, std::string::iterator& it_end) {

    if (it_end == it_begin) {
        return false;
    }

    int count = 0;

    for (; it_begin != it_end; ++it_begin) {

        count++;

        if (count == 5) {
            return false;
        }

        if (!isHexadecimalDigit(*it_begin)) {
            return false;
        }

    }

    return true;
}

std::string validateIPv4Address(std::string str) {
    auto it_begin = str.begin();
    std::string::iterator it_end;
    for (int i = 0; i < 3; ++i) {
        it_end = std::find(it_begin, str.end(), '.');

        if (!checkIPv4Validity(it_begin, it_end) || it_begin == str.end()) {
            return Neither;
        }

        it_begin++;
    }
    it_end = str.end();
    if (!checkIPv4Validity(it_begin, it_end)) {
        return Neither;
    }

    return IPv4;
}

std::string validateIPv6Address(std::string str) {
    auto it_begin = str.begin();
    std::string::iterator it_end;
    for (int i = 0; i < 7; ++i) {
        it_end = std::find(it_begin, str.end(), ':');

        if (!checkIPv6Validity(it_begin, it_end) || it_begin == str.end()) {
            return Neither;
        }

        it_begin++;
    }
    it_end = str.end();
    if (!checkIPv6Validity(it_begin, it_end)) {
        return Neither;
    }

    return IPv6;
}

std::string validIPAddress(std::string IP) {
    if (IP.find('.') != std::string::npos) {
        return validateIPv4Address(IP);
    }

    if (IP.find(':') != std::string::npos) {
        std::transform(IP.begin(), IP.end(), IP.begin(), [](char c) {return std::tolower(c);});
        return validateIPv6Address(IP);
    }

    return Neither;
}

int main() {
    std::string addr = "192.0.0.1";
    std::cout << validIPAddress(addr);
    return 0;
}