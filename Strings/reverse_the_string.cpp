#include <iostream>
#include <string>

void eraseLastSpace(std::string& res) {
    if (!res.empty()) {
        res.erase(res.size() - 1, 1);
    }
}

std::string solve(std::string str) {
    std::string res;
    int pos = (int) str.size() - 1;
    int end_pos;

    for (; pos >= 0; --pos) {
        for (; pos >= 0; --pos) {
            if (str[pos] != ' ')
                break;
        }

        if (pos == -1) {
            eraseLastSpace(res);
            return res;
        }

        end_pos = pos;
        for (; pos >= 0; --pos) {
            if (str[pos] == ' ')
                break;
        }

        res += str.substr(pos + 1, end_pos - pos) + " ";
    }

    eraseLastSpace(res);

    return res;
}

int main() {
    std::string str = "  hello world! ";
    std::cout << "---" << solve(str) << "---";
    return 0;
}