// Equal
#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

vector<int> equal(vector<int> &A) {
    std::unordered_map<int, std::pair<int, int>> sum_to_pair;
    std::vector<int> results(4, INT_MAX);
    std::vector<int> curr_res;
    for (int i = 0; i < A.size() - 1; ++i) {
        for (int j = i + 1; j < A.size(); ++j) {
            if (sum_to_pair.find(A[i] + A[j]) == sum_to_pair.end()) {
                sum_to_pair[A[i] + A[j]] = {i, j};
            } else {
                auto res = sum_to_pair[A[i] + A[j]];
                if (res.first != i && res.second != i && res.first != j && res.second != j) {
                    curr_res = {res.first, res.second, i, j};
                    if (curr_res < results) {results = curr_res;}
                }
            }
        }
    }

    if (results == std::vector<int>(4, INT_MAX)) {
        return {};
    }

    return results;
}

