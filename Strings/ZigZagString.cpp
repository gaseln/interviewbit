#include <iostream>
#include <string>

std::string convert(std::string str, int num_rows) {

    if (num_rows == 1) {
        return str;
    }

    std::string res;
    int second_jump = 0, first_jump = 2 * (num_rows - 1);
    bool second_jump_flag = false;
    int dist = 0, length = (int) str.length();
    for (int i = 0; i < num_rows; ++i) {
        dist = i;
        while (dist < length) {
            res += str[dist];

            if (second_jump == 0) {
                second_jump_flag = false;
            }

            if (first_jump == 0) {
                second_jump_flag = true;
            }

            dist += (second_jump_flag) ? second_jump : first_jump;

            second_jump_flag = !second_jump_flag;
        }
        second_jump += 2;
        first_jump -= 2;
        second_jump_flag = false;
    }

    return res;
}

int main() {
    std::string input = "A";
    std::cout << convert(input, 1);
    return 0;
}