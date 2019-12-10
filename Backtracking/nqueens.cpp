// NQueens
#include <iostream>
#include <vector>
#include <string>

bool isAttacking(int x, int line1, int y, int line2) {
    // Checks whether queens at position x on line line1 attacks
    // another queen at position y on line line2. line2 always larger line1
    return  (x == y || abs(x - y) == line2 - line1);
}

void helper(std::vector<int>& curr, int& pos, int& pos_max, std::vector<std::vector<int>>& results) {
    int i, j;
    bool isAttacking_flag = false;
    if (pos == pos_max) {
        results.emplace_back(curr);
    }

    for (i = 0; i < pos_max; ++i) {

        if (!curr.empty()) {
            for (j = 0; j < curr.size(); ++j) {
                isAttacking_flag = isAttacking(curr[j], j, i, pos);

                if (isAttacking_flag) {
                    break;
                }
            }
        }

        if (!isAttacking_flag) {
            curr.push_back(i);
            pos++;
            helper(curr, pos, pos_max, results);
            pos--;
            curr.pop_back();
        }

    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<int> current;
    current.reserve(n);
    int pos = 0;
    std::vector<std::vector<int>> intermediate_results;
    helper(current, pos, n, intermediate_results);
    std::string empty_line = std::string(n, '.');
    std::vector<std::vector<std::string>> results;
    results.reserve(intermediate_results.size());
    std::vector<std::string> comb;
    for (auto& current_comb : intermediate_results) {
        comb.clear();
        for (auto& el : current_comb){
            empty_line[el] = 'Q';
            comb.push_back(empty_line);
            empty_line[el] = '.';
        }

        results.push_back(comb);
    }

    return results;
}

int main() {
    auto res = solveNQueens(5);
    for (auto& comb : res) {
        for (auto& line : comb) {
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
    }
}
