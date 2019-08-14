#include <iostream>
#include <ctype.h>
#include <string>

int isPalindrome(std::string str) {
    std::string str_modified;
    for (char symbol : str) {
        if (isalnum(symbol)) {
            str_modified += char(std::tolower(symbol));
        }
    }

    if (str_modified.size() < 2) {
        return 1;
    }

    int b_ind = 0;
    int e_ind = int(str_modified.size() - 1);

    while (e_ind - b_ind >= 1) {
        if (str_modified[e_ind] != str_modified[b_ind]) {
            return 0;
        }
        e_ind--;
        b_ind++;
    }

    return 1;
}

int main() {
    std::string str = "A man, a plan, a canal: Panama\"";
    std::cout << isPalindrome(str) << std::endl;
    return 0;
}