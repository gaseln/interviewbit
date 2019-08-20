#include <iostream>
#include <string>
#include <vector>

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

std::string resultingString(std::string& s, int i) {

    if (i == s.size() - 1) {
        return s;
    }

    std::string res;
    for (int ind = i + 1; ind < s.size(); ++ind) {
        res += s[ind];
    }
    std::reverse(res.begin(), res.end());
    res += s;

    return res;
}

std::string solve(std::string s) {
    // special cases
    if (s.size() < 2) {
        return s;
    }

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

    /*
     * computing analogous beta-function: beta[i] for string "str"
     * is equal to the length of the longest common prefix of "str" and
     * reversed "str" ending at position i
     */

    std::vector<int> beta_function(s.size());
    l = r = (int) s.size();
    for (int i = (int) s.size() - 1; i >= 0; --i) {
        if (i < l) {
            j_prefix = 0;
            j = i;
            std::tie(l, r) = shortestPalindromeReversedSearch(s, beta_function, i, j_prefix, j);

            /*
             * in order to solve the problem we do not need to compute beta-function till index 0,
             * if beta_function[i] is not smaller than half a distance till the beginning of "str",
             * then the longest "internal" palindrome is found
             */

            if (beta_function[i] >= ((i + 1) / 2)) {
                return resultingString(s, i);
            }
        } else {

            if (z_function[r - i] < i - l + 1) {
                beta_function[i] = z_function[r - i];
            } else {
                j_prefix = i - l + 1;
                j = l - 1;
                std::tie(l, r) = shortestPalindromeReversedSearch(s, beta_function, i, j_prefix, j);

                if (beta_function[i] >= (i / 2)) {
                    return resultingString(s, i);
                }
            }
        }
    }

    // for debugging purposes; if the function works correctly, it will never reach this line
    return "ERROR";
}

int main() {
//    std::string s = "abcd";
    std::string s = "aacecaaa";
    auto z = solve(s);
    for (auto el : z) {
        std::cout << el ;
    }
    return 0;
}