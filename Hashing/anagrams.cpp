// Anagrams
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string sortLinear(const std::string& str) {
    std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f',
                                  'g', 'h', 'i', 'j', 'k', 'l',
                                  'm', 'n', 'o', 'p', 'q', 'r',
                                  's', 't', 'u', 'v', 'w', 'x',
                                  'y', 'z'};
    std::unordered_map<char, int> char_to_count;
    for (const auto& el : str) {
        if (char_to_count.find(el) == char_to_count.end()) {
            char_to_count[el] = 1;
        } else {
            char_to_count[el]++;
        }
    }

    std::string res;
    int i;
    for (const auto& sym : alphabet) {
        if (char_to_count.find(sym) != char_to_count.end()) {
            for (i = 0; i < char_to_count[sym]; ++i) {
                res += sym;
            }
        }
    }

    return res;
}

std::vector<std::vector<std::string>> anagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    for (const auto& str : strs) {
        anagrams[sortLinear(str)].push_back(str);
    }
    std::vector<std::vector<std::string>> result;
    for (const auto& el : anagrams) {
        result.push_back(el.second);
    }
    return result;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = anagrams(words);
}