#include <iostream>
#include <vector>
#include <string>

std::string emptySpaces(int num) {
    std::string res;

    for (int i = 0; i < num; ++i) {
        res += " ";
    }

    return res;
}

std::vector<std::string> fullJustify(std::vector<std::string>& words, int L) {
    int full_length = 0;
    int approx_space_length;
    int left_empty_space_length = 0;
    int right_empty_space_length = 0;
    int left_empty_space_count = 0;
    int num_words;
    std::string res_line;
    std::vector<std::string> res;

    int start_index = 0, iter;
    while (start_index != words.size()) {

        iter = start_index;
        res_line = "";
        full_length = (int) words[iter].length();
        approx_space_length = 0;

        while (full_length + approx_space_length <= L) {
            iter++;
            approx_space_length += 1;

            if (iter == words.size()) {
                break;
            }

            full_length += words[iter].length();
        }

        full_length -= (iter == words.size()) ? 0 : words[iter].length();
        num_words = iter - start_index;

        if (num_words == 1) {
            res.push_back(words[start_index] + emptySpaces(L - full_length));
            start_index = iter;
            continue;
        }

        if (iter == words.size()) {
            left_empty_space_length = 1;
            left_empty_space_count = num_words - 1;
        } else {
            right_empty_space_length = (L - full_length) / (num_words - 1);
            left_empty_space_length = right_empty_space_length + 1;
            left_empty_space_count = L - full_length - right_empty_space_length * (num_words - 1);
        }


        for (int ind = start_index; ind < iter - 1; ++ind) {
            res_line += words[ind];
            res_line += (left_empty_space_count) ? emptySpaces(left_empty_space_length) : emptySpaces(right_empty_space_length);
            left_empty_space_count -= (left_empty_space_count) ? 1 : 0;
        }

        res_line += words[iter - 1];
        res_line += (iter == words.size()) ? emptySpaces(L - full_length - num_words + 1) : "";
        res.push_back(res_line);
        start_index = iter;
    }

    return res;
}

int main() {
    std::vector<std::string> input = {"This", "is", "an", "example", "of", "text", "justification."};
    auto res = fullJustify(input, 16);
    for (auto& el : res) {
        std::cout << el << std::endl;
    }
    return 0;
}