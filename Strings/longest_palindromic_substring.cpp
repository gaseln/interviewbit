#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::pair<int, int> shortestPalindromeSearch(std::string& s, std::vector<int>& z_function, int& i, int& j_prefix, int& j) {

    while (s[j_prefix] == s[j]) {

        ++j_prefix;
        ++j;

        if (j == s.size()) {
            break;
        }

    }

    z_function.push_back(j_prefix);
    int l = i;
    int r = i + j_prefix  - 1;
    return {l, r};
}

std::pair<int, int> shortestPalindromeReversedSearch(std::string& s, std::vector<int>& beta_function, int& i, int& j_prefix, int& j) {

    while (s[j_prefix] == s[j]) {

        ++j_prefix;
        --j;

        if (j == -1) {
            break;
        }

    }

    beta_function[i] = j_prefix;
    int r = i;
    int l = i - j_prefix  + 1;
    return {l, r};
}

std::string longestPalindrome(std::string s) {
    // special cases
    if (s.size() < 2) {
        return s;
    }
    int longest_palindrome_length = 0;
    std::string longest_palindrome;

    while (s.size() > 0) {
        // computing Z-function, see https://cp-algorithms.com/string/z-function.html
        int l, r, j_prefix, j;
        l = r = -1;
        std::vector<int> z_function;
        z_function.push_back(0);

        for (int i = 1; i < s.size(); ++i) {
            if (i > r) {

                j_prefix = 0;
                j = i;

                std::tie(l, r) = shortestPalindromeSearch(s, z_function, i, j_prefix, j);

            } else {

                if (z_function[i - l] < (r - i + 1)) {
                    z_function.push_back(z_function[i-l]);
                } else {

                    j_prefix = r - i + 1;
                    j = r + 1;

                    std::tie(l, r) = shortestPalindromeSearch(s, z_function, i, j_prefix, j);
                }
            }
        }

        std::vector<int> beta_function(s.size());
        l = r = (int) s.size();
        for (int i = (int) s.size() - 1; i >= 0; --i) {
            if (i < l) {
                j_prefix = 0;
                j = i;
                std::tie(l, r) = shortestPalindromeReversedSearch(s, beta_function, i, j_prefix, j);

                if (beta_function[i] >= ((i + 1) / 2)) {
                    if (i + 1 > longest_palindrome_length) {
                        longest_palindrome_length = i + 1;
                        longest_palindrome = s.substr(0, i + 1);
                        break;
                    }
                }
            } else {

                if (z_function[r - i] < i - l + 1) {
                    beta_function[i] = z_function[r - i];
                } else {
                    j_prefix = i - l + 1;
                    j = l - 1;
                    std::tie(l, r) = shortestPalindromeReversedSearch(s, beta_function, i, j_prefix, j);

                    if (beta_function[i] >= ((i + 1) / 2)) {
                        if (i + 1 > longest_palindrome_length) {
                            longest_palindrome_length = i + 1;
                            longest_palindrome = "";
                            longest_palindrome = s.substr(0, i + 1);
                            break;
                        }
                    }
                }
            }
        }

        z_function.clear();
        beta_function.clear();
        s.erase(0, 1);
    }

    return longest_palindrome;
}

int main() {
    std::string str = "babad";
    auto res = longestPalindrome(str);
    for (auto el : res) {
        std::cout << el;
    }
    return 0;
}


