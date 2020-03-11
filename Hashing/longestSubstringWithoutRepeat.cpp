#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    int max = 0, curr_max = 0, curr_start_ind = 0;
    std::unordered_map<char, int> char_to_index;
    for (int ind = 0; ind < s.length(); ++ind) {
        if (char_to_index.find(s[ind]) == char_to_index.end() || char_to_index[s[ind]] < curr_start_ind) {
            char_to_index[s[ind]] = ind;
            curr_max += 1;
        } else {
            if (max < curr_max) max = curr_max;
            curr_start_ind = char_to_index[s[ind]] + 1;
            char_to_index[s[ind]] = ind;
            curr_max = ind + 1 - curr_start_ind;
        }
    }

    return std::max(max, curr_max);
}

int main() {
    std::string s = "abcd";
    std::cout << lengthOfLongestSubstring(s);
}