#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using unint = unsigned int;
using lunint = unsigned long long;

unint hash_(const std::string& word, unint base, unint p) {
    unint hash_ = 0;
    for (const char& sym : word) {
        hash_ = (((lunint) hash_ * base) % p + sym - 'a' + 1) % p;
    }
    return hash_;
}

unint base_size_mod(unint base, unint p, unint size) {
    unint res = 1;
    for (unint i = 0; i < size; ++i) {
        res = ((lunint) res * base) % p;
    }
    return res;
}

unint appendAndSkip(unint hash, char append_char, char skip_char, unint base, unint p, unint magic) {
    return (((lunint) hash * base) % p + (lunint) (skip_char - 'a' + 1) * (p - magic) + append_char - 'a' + 1) % p;
}

void update_hash_vector(std::vector<unint>& curr_hashes, std::string& str, unint pos, unint word_size, unint base, unint p, unint magic) {
    for (auto& hash: curr_hashes) {
        hash = appendAndSkip(hash, str[pos + word_size], str[pos], base, p, magic);
        pos += word_size;
    }
}

std::vector<int> findSubstring(std::string s, const std::vector<std::string>& words) {
    //Defining constants, computing <<magic>> constant
    unint word_size = words[0].size();
    unint word_count = words.size();
    unint base = 29;
    unint p = 1000000009;
    auto magic = base_size_mod(base, p, word_size);

    //Creating a map of hashes and a map of words
    std::map<unint, unint> hash_map;
    std::map<std::string, unint> word_map;
    for (const std::string& word : words) {
        auto curr_hash = hash_(word, base, p);
        if (hash_map.find(curr_hash) == hash_map.end()) {
            hash_map[curr_hash] = 1;
        } else {
            hash_map[curr_hash] += 1;
        }
        if (word_map.find(word) == word_map.end()) {
            word_map[word] = 1;
        } else {
            word_map[word] += 1;
        }
    }

    std::vector<int> res;

    if (s.size() < word_size * word_count) {
        return res;
    }

    std::vector<unint> curr_hashes;
    for (unint i = 0; i < word_count; ++i) {
        auto substr = s.substr(i * word_size, word_size);
        curr_hashes.emplace_back(hash_(substr, base, p));
    }

    unint begin_it = 0;
    unint sum;
    while (true) {
        auto hash_map_copy = hash_map;
        for (auto& hash: curr_hashes) {
            if ((hash_map_copy.find(hash) == hash_map_copy.end()) or (hash_map_copy[hash] == 0)){
                break;
            }
            hash_map_copy[hash] -= 1;
        }

        sum = 0;
        for (auto const& [key, val] : hash_map_copy) {
            sum += val;
        }

        if (sum == 0) {
            auto word_map_copy = word_map;
            for (unint i = 0; i < word_count; ++i) {
                auto substr = s.substr(begin_it + i * word_size, word_size);
                if ((word_map_copy.find(substr) == word_map_copy.end()) or (word_map_copy[substr] == 0)){
                    break;
                }
                word_map_copy[substr] -= 1;
            }
            sum = 0;
            for (auto const& [key, val] : word_map_copy) {
                sum += val;
            }

            if (sum == 0) {
                res.emplace_back(begin_it);
            }
        }

        if (begin_it + 1 + word_size * word_count > s.size()) {
            break;
        }

        update_hash_vector(curr_hashes, s, begin_it, word_size, base, p, magic);
        begin_it += 1;
    }

    return res;
}

int main() {
    std::string s = "barfoofoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobarthefoobar";
    std::vector<std::string> words = {"bar","foo","the"};
    auto res = findSubstring(s, words);
    return 0;
}