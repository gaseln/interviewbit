#include <iostream>
#include <unordered_map>
#include <string>

std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> t_char_to_count;

    for (auto& el : t) {
        t_char_to_count[el] += 1;
    }

    std::unordered_map<char, int> s_char_to_count;

    int start_ind = 0, count = 0, min_length = INT_MAX, curr_min = 0, star_start_ind = -1;
    const int ref_count = t_char_to_count.size();
    for (int ind = 0; ind < s.length(); ++ind) {
        ++curr_min;

        if (t_char_to_count.find(s[ind]) == t_char_to_count.end()) {
            continue;
        }

        s_char_to_count[s[ind]] += 1;
        if (s_char_to_count[s[ind]] == t_char_to_count[s[ind]]) ++count;

        while (count == ref_count) {
            if (s_char_to_count.find(s[start_ind]) != s_char_to_count.end()) {
                --s_char_to_count[s[start_ind]];

                if (s_char_to_count[s[start_ind]] < t_char_to_count[s[start_ind]]) {
                    count--;
                    if (curr_min < min_length || (curr_min == min_length && star_start_ind == -1)) {
                        star_start_ind = start_ind;
                        min_length = curr_min;
                    }
                }
            }

            --curr_min;
            ++start_ind;
        }
    }

    return (star_start_ind == -1) ? "" : s.substr(star_start_ind, min_length);
}